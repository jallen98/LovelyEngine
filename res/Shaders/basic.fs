#version 330 core

struct Light {
    vec3 position;
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
uniform Light light;
uniform Material material;

void main()
{
    vec3 ambient = light.ambient * texture(material.diffuse, texCoord).rgb;

    vec3 lightDir = normalize(light.position - fragPos);
    vec3 diffuse = light.diffuse * max(dot(normal, lightDir), 0.0) * texture(material.diffuse, texCoord).rgb;

    vec3 viewDir = normalize(cameraPos - fragPos);
    vec3 reflectDir = reflect(-lightDir, normal);
    vec3 specular = light.specular * pow(max(dot(viewDir, reflectDir), 0.0), material.shininess) * texture(material.specular, texCoord).rgb;

    fragColor = vec4(ambient + diffuse + specular, 1.0);
}
