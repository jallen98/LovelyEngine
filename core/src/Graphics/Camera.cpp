#include "Graphics/Camera.h"

#include "System/Utility.h"

#include <algorithm>
#include <cmath>
#include <iostream>

lov::Graphics::Camera::Camera(const Vector3f& position, const Vector3f& worldUp, float pitch, float yaw):
    m_position(position),
    m_worldUp(worldUp),
    m_pitch(pitch),
    m_yaw(yaw),
    m_clampPitch(false),
    m_pitchLow(-89.0f),
    m_pitchHigh(89.0f),
    m_lockTarget(false)
{
    this->calculateViewMatrix();
}

lov::Graphics::Camera::Camera(const Vector3f& position, const Vector3f& worldUp, const Vector3f& target):
    m_position(position),
    m_worldUp(worldUp),
    m_target(target),
    m_clampPitch(false),
    m_pitchLow(-89.0f),
    m_pitchHigh(89.0f),
    m_lockTarget(true)
{
    this->calculateViewMatrix();
}

void lov::Graphics::Camera::move(const Vector3f& offset, float velocity) {
    m_position += Vector::normalize(offset) * velocity;
    this->calculateViewMatrix();
}

void lov::Graphics::Camera::move(float x, float y, float z, float velocity) {
    this->move({ x, y, z }, velocity);
}

void lov::Graphics::Camera::rotate(float yawOffset, float pitchOffset, float sensitivity) {
    m_yaw += yawOffset * sensitivity;
    m_pitch += pitchOffset * sensitivity;

    if (m_clampPitch) {
        m_pitch = std::clamp(m_pitch, m_pitchLow, m_pitchHigh);
    }

    this->calculateViewMatrix();
}

void lov::Graphics::Camera::setPosition(const Vector3f& position) {
    m_position = position;
    this->calculateViewMatrix();
}

void lov::Graphics::Camera::setPosition(float x, float y, float z) {
    this->setPosition({ x, y, z });
}

void lov::Graphics::Camera::setWorldUp(const Vector3f& up) {
    m_worldUp = up;
    this->calculateViewMatrix();
}

void lov::Graphics::Camera::setWorldUp(float x, float y, float z) {
    this->setWorldUp({ x, y, z });
}

void lov::Graphics::Camera::setRotation(float yaw, float pitch) {
    m_yaw = yaw;
    m_pitch = pitch;

    if (m_clampPitch) {
        m_pitch = std::clamp(m_pitch, m_pitchLow, m_pitchHigh);
    }

    this->calculateViewMatrix();
}

void lov::Graphics::Camera::shouldLockTarget(bool lockOn) {
    m_lockTarget = lockOn;
    this->calculateViewMatrix();
}

void lov::Graphics::Camera::setTarget(const Vector3f& target) {
    m_target = target;
    this->calculateViewMatrix();
}

void lov::Graphics::Camera::clampPitch(bool clamp, float low, float high) {
    m_clampPitch = clamp;
    m_pitchLow = low;
    m_pitchHigh = high;
}

void lov::Graphics::Camera::setTarget(float x, float y, float z) {
    this->setTarget({ x, y, z });
}

lov::Vector3f lov::Graphics::Camera::getPosition() const {
    return m_position;
}

lov::Vector3f lov::Graphics::Camera::getFront() const {
    return m_front;
}

lov::Vector3f lov::Graphics::Camera::getRight() const {
    return m_right;
}

lov::Vector3f lov::Graphics::Camera::getUp() const {
    return m_up;
}

lov::Vector3f lov::Graphics::Camera::getWorldUp() const {
    return m_worldUp;
}

float lov::Graphics::Camera::getPitch() const {
    return m_pitch;
}

float lov::Graphics::Camera::getYaw() const {
    return m_yaw;
}

lov::Graphics::Transform lov::Graphics::Camera::getViewMatrix() const {
    return Transform::lookAt(m_position, m_position + m_front, m_up);
}

void lov::Graphics::Camera::calculateViewMatrix() {
    if (m_lockTarget) {
        m_front = Vector::normalize(m_target - m_position);
    }
    else {
        m_front.x = cos(Util::toRadians(m_yaw)) * cos(Util::toRadians(m_pitch));
        m_front.y = sin(Util::toRadians(m_pitch));
        m_front.z = sin(Util::toRadians(m_yaw)) * cos(Util::toRadians(m_pitch));
        m_front = Vector::normalize(m_front);
    }

    m_right = Vector::normalize(Vector::cross(m_front, m_worldUp));
    m_up = Vector::normalize(Vector::cross(m_right, m_front));
}
