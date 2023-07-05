#version 330 core

struct PointLight {
    vec3 position;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;

    float attenuationConstant;
    float attenuationLinear;
    float attenuationQuadratic;
};
#define POINT_LIGHT_COUNT 4

struct SpotLight {
    vec3 position;
    vec3 direction;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;

    float innerCutoff;
    float outerCutoff;

    float attenuationConstant;
    float attenuationLinear;
    float attenuationQuadratic;
};

struct DirectionalLight {
    vec3 direction;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

struct Material {
    sampler2D diffuse;
    sampler2D specular;
    float shininess;
};

in vec3 fragPos;
in vec3 normal;
in vec2 texCoord;

out vec4 fragColor;

uniform vec3 cameraPos;
uniform Material material;

uniform PointLight pointLights[POINT_LIGHT_COUNT];
uniform SpotLight flashlight;
uniform DirectionalLight sun;

float calculateAttenuation(float distance, float constant, float linear, float quadratic) {
    return 1.0 / (constant + linear * distance + quadratic * distance * distance);
}

vec3 calculatePointLight(PointLight light, vec3 viewDir) {
    vec3 lightDir = normalize(light.position - fragPos);
    vec3 reflectDir = reflect(-lightDir, normal);

    float distance = length(light.position - fragPos);
    float attenuation = calculateAttenuation(distance, light.attenuationConstant, light.attenuationLinear, light.attenuationQuadratic);

    vec3 ambient = light.ambient * texture(material.diffuse, texCoord).rgb * attenuation;
    vec3 diffuse = light.diffuse * max(dot(normal, lightDir), 0.0) * texture(material.diffuse, texCoord).rgb * attenuation;
    vec3 specular = light.specular * pow(max(dot(viewDir, reflectDir), 0.0), material.shininess) * texture(material.specular, texCoord).rgb * attenuation;

    return (ambient + diffuse + specular);
}

vec3 calculateSpotLight(SpotLight light, vec3 viewDir) {
    vec3 lightDir = normalize(light.position - fragPos);
    vec3 reflectDir = reflect(-lightDir, normal);

    float distance = length(light.position - fragPos);
    float attenuation = calculateAttenuation(distance, light.attenuationConstant, light.attenuationLinear, light.attenuationQuadratic);

    float theta = dot(lightDir, normalize(-light.direction));
    float epsilon = light.innerCutoff - light.outerCutoff;
    float intensity = clamp((theta - light.outerCutoff) / epsilon, 0.0, 1.0);

    vec3 ambient = light.ambient * texture(material.diffuse, texCoord).rgb * attenuation;
    vec3 diffuse = light.diffuse * max(dot(normal, lightDir), 0.0) * texture(material.diffuse, texCoord).rgb * attenuation * intensity;
    vec3 specular = light.specular * pow(max(dot(viewDir, reflectDir), 0.0), material.shininess) * texture(material.specular, texCoord).rgb * attenuation * intensity;

    return (ambient + diffuse + specular);
}

vec3 calculateDirectionalLight(DirectionalLight light, vec3 viewDir) {
    vec3 lightDir = normalize(-light.direction);
    vec3 reflectDir = reflect(-lightDir, normal);

    vec3 ambient = light.ambient * texture(material.diffuse, texCoord).rgb;
    vec3 diffuse = light.diffuse * max(dot(normal, lightDir), 0.0) * texture(material.diffuse, texCoord).rgb;
    vec3 specular = light.specular * pow(max(dot(viewDir, reflectDir), 0.0), material.shininess) * texture(material.specular, texCoord).rgb;

    return (ambient + diffuse + specular);
}

void main()
{
    // Calculated values
    vec3 viewDir = normalize(cameraPos - fragPos);

    // Initial light value
    vec3 lightResult = vec3(0.0);

    // Calculate directional light
    lightResult += calculateDirectionalLight(sun, viewDir);

    // Calculate point lights
    for (int i = 0; i < POINT_LIGHT_COUNT; i++) {
        lightResult += calculatePointLight(pointLights[i], viewDir);
    }

    // Calculate spot light
    lightResult += calculateSpotLight(flashlight, viewDir);

    fragColor = vec4(lightResult, 1.0);
}
