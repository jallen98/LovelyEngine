#pragma once

#include "Graphics/Transform.h"
#include "System/Vector.h"

/// @file Camera.h
/// @brief A camera object that can be used to get a view transform

namespace lov {
    namespace Graphics {
        /// @brief A camera that can be moved and rotated, and can provide an associated view matrix
        class Camera {
        public:
            /// @brief Construct this camera with the given pitch and yaw
            /// @param position The position of the camera in world space
            /// @param worldUp The up direction of world space
            /// @param pitch The pitch of the camera
            /// @param yaw The yaw of the camera
            Camera(const Vector3f& position, const Vector3f& worldUp, float pitch, float yaw);

            /// @brief Construct this camera with the given target, automatically enabling target lock
            /// @param position The position of the camera in world space
            /// @param worldUp The up direction of world space
            /// @param target The target of the camera in world space
            /// @see #lov::Graphics::Camera::shouldLockTarget for information on target lock
            Camera(const Vector3f& position, const Vector3f& worldUp, const Vector3f& target);

            /// @brief Move the position of this camera by the given offset and velocity
            /// @param offset The offset by which to move this camera, which will be normalized
            /// @param velocity The velocity of movement
            void move(const Vector3f& offset, float velocity);

            /// @brief Move the position of this camera by the given offsets, which will be normalized, and velocity
            /// @param x The x direction of movement
            /// @param y The y direction of movement
            /// @param z The z direction of movement
            /// @param velocity The velocity of movement
            void move(float x, float y, float z, float velocity);

            /// @brief Rotate this camera by the given yaw and pitch offsets
            /// @param yawOffset The yaw offset
            /// @param pitchOffset The pitch offset
            /// @param sensitivity Sensitivity of the rotation
            void rotate(float yawOffset, float pitchOffset, float sensitivity);

            /// @brief Set the position of this camera
            /// @param position The new camera position
            void setPosition(const Vector3f& position);

            /// @brief Set the position of this camera
            /// @param x The x coordinate of this camera
            /// @param y The y coordinate of this camera
            /// @param z The z coordinate of this camera
            void setPosition(float x, float y, float z);

            /// @brief Set the direction of up in world space
            /// @param up The direction of up in world space
            void setWorldUp(const Vector3f& up);

            /// @brief Set the direction of up in world space
            /// @param x The x component of world space up
            /// @param y The y component of world space up
            /// @param z The z component of world space up
            void setWorldUp(float x, float y, float z);

            /// @brief Set the rotation of this camera
            /// @param yaw The yaw of this camera
            /// @param pitch The pitch of this camera
            void setRotation(float yaw, float pitch);

            /// @brief Sets the camera to look at its target, ignoring pitch and yaw
            /// @param lockOn Should this camera lock onto its target?
            void shouldLockTarget(bool lockOn);

            /// @brief Set the target of this camera, only used if shouldLockTarget is enabled
            /// @param target This camera's target
            void setTarget(const Vector3f& target);

            /// @brief Set the target of this camera, only used if shouldLockTarget is enabled
            /// @param x The x component of this camera's target
            /// @param y The y component of this camera's target
            /// @param z The z component of this camera's target
            void setTarget(float x, float y, float z);

            /// @brief Clamp the pitch value
            /// @param clamp Whether to clamp pitch
            /// @param low Minimum pitch value, default -89.0
            /// @param hight Maximum pitch value, default 89.0
            void clampPitch(bool clamp, float low = -89.0f, float high = 89.0f);

            /// @brief Get the position of this camera
            /// @return This camera's position
            Vector3f getPosition() const;

            /// @brief Get the front direction of this camera
            /// @return The direction this camera is facing
            Vector3f getFront() const;

            /// @brief Get the right direction of this camera orthogonal to its front and world up
            /// @return The right direction of this camera
            Vector3f getRight() const;

            /// @brief Get the up direction of this camera orthogonal to its front and right
            /// @return The up direction of this camera
            Vector3f getUp() const;

            /// @brief Get the up diraction of world space of this camera
            /// @return The world space up
            Vector3f getWorldUp() const;

            /// @brief Get the pitch of this camera
            /// @return The pitch of this camera
            float getPitch() const;

            /// @brief Get the yaw of this camera
            /// @return The yaw of this camera
            float getYaw() const;

            /// @brief Get the view matrix for this camera
            /// @return The view matrix for this camera
            Transform getViewMatrix() const;

        private:
            /// @brief Helper to calculate view matrix after changes are made
            void calculateViewMatrix();

            Vector3f m_worldUp; ///< Up in world space

            Vector3f m_position; ///< The position of this camera
            Vector3f m_front; ///< The front of this camera
            Vector3f m_right; ///< The right direction of this camera
            Vector3f m_up; ///< The up direction of this camera

            float m_pitch; ///< The pitch of this camera
            float m_yaw; ///< The yaw of this camera

            bool m_clampPitch; ///< Should the pitch be clamped?
            float m_pitchLow; ///< Minimum value of pitch if clamp enabled
            float m_pitchHigh; ///< Maximum value of pitch if clamp enabled

            Vector3f m_target; ///< The target of this camera
            bool m_lockTarget; ///< Is this camera locked onto the target?
        };
    }
}
