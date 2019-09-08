/****************************************************************************
 *
 *   Copyright (c) 2019 PX4 Development Team. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name PX4 nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

/**
 * @file FlightTaskManualPosition.hpp
 *
 * Flight task for manual position controlled mode.
 *
 */

#pragma once

#include "FlightTaskManual.hpp"
#include "PositionLock.hpp"

class FlightTaskManualAcceleration : public FlightTaskManual
{
public:
	FlightTaskManualAcceleration();

	virtual ~FlightTaskManualAcceleration() = default;
	bool initializeSubscriptions(SubscriptionArray &subscription_array) override;
	bool activate(vehicle_local_position_setpoint_s last_setpoint) override;
	bool updateInitialize() override;
	bool update() override;

protected:
	PositionLock _position_lock; /**< object taking care of altitude and yaw lock logic */

	DEFINE_PARAMETERS_CUSTOM_PARENT(FlightTaskManual,
					(ParamFloat<px4::params::MPC_VEL_MANUAL>) _param_mpc_vel_manual,
					(ParamFloat<px4::params::MPC_ACC_HOR_MAX>) _param_mpc_acc_hor_max,
					(ParamFloat<px4::params::MPC_HOLD_MAX_XY>) _param_mpc_hold_max_xy,
					(ParamFloat<px4::params::MPC_ACC_HOR_ESTM>) _param_mpc_acc_hor_estm,
					(ParamFloat<px4::params::MPC_MAN_Y_MAX>) _param_mpc_man_y_max
				       )
private:

};
