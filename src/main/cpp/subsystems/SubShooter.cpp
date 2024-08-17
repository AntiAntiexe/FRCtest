// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubShooter.h"
#include <frc/smartdashboard/SmartDashboard.h>

SubShooter::SubShooter() = default;

// This method will be called once per scheduler run
void SubShooter::Periodic() {
    frc::SmartDashboard::PutNumber("shooter speed", _shooterMotor.Get());
}

frc2::CommandPtr SubShooter::SpinFlywheel(){
    return StartEnd(
        [this]
        {
            _shooterMotor.Set(0.8); // On start
        },
        [this]
        {
            _shooterMotor.Set(0); // On End
        });

}