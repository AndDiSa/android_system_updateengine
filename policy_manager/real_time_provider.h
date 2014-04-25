// Copyright (c) 2014 The Chromium OS Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CHROMEOS_PLATFORM_UPDATE_ENGINE_POLICY_MANAGER_REAL_TIME_PROVIDER_H_
#define CHROMEOS_PLATFORM_UPDATE_ENGINE_POLICY_MANAGER_REAL_TIME_PROVIDER_H_

#include <base/memory/scoped_ptr.h>
#include <base/time/time.h>

#include "update_engine/clock_interface.h"
#include "update_engine/policy_manager/time_provider.h"

namespace chromeos_policy_manager {

// TimeProvider concrete implementation.
class RealTimeProvider : public TimeProvider {
 public:
  explicit RealTimeProvider(chromeos_update_engine::ClockInterface* clock)
      : clock_(clock) {}

  // Initializes the provider and returns whether it succeeded.
  bool Init();

  virtual Variable<base::Time>* var_curr_date() override {
    return var_curr_date_.get();
  }

  virtual Variable<int>* var_curr_hour() override {
    return var_curr_hour_.get();
  }

 private:
  // A clock abstraction (fakeable).
  chromeos_update_engine::ClockInterface* const clock_;

  scoped_ptr<Variable<base::Time>> var_curr_date_;
  scoped_ptr<Variable<int>> var_curr_hour_;

  DISALLOW_COPY_AND_ASSIGN(RealTimeProvider);
};

}  // namespace chromeos_policy_manager

#endif  // CHROMEOS_PLATFORM_UPDATE_ENGINE_POLICY_MANAGER_REAL_TIME_PROVIDER_H_
