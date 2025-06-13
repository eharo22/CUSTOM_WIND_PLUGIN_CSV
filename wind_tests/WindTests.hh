/*
 * Copyright (C) 2019 Open Source Robotics Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#ifndef GZ_SIM_SYSTEMS_WINDTESTS_HH_
#define GZ_SIM_SYSTEMS_WINDTESTS_HH_

#include <memory>

#include "gz/sim/System.hh"

namespace gz
{
  namespace sim
  {
    // Forward declarations
    class EntityComponentManager;
    class EventManager;

    namespace systems
    {
      // Forward declarations
      class WindTestsPrivate; // Changed from WindEffectsPrivate

      /// \brief This system applies wind effects to models.
      /// The wind force is computed based on a linear velocity seed and can
      /// be varied with noise and sine waves.
      /// The wind velocity can be set via a `/world/<world_name>/wind` topic
      /// with `gz.msgs.Wind` messages.
      ///
      /// The wind effects can be configured using the following SDF parameters:
      /// 
      /// <plugin filename="gz-sim-wind-tests-system"
      ///         name="gz::sim::systems::WindTests">
      ///   <horizontal>
      ///     <magnitude>
      ///       <time_for_rise>1.0</time_for_rise>
      ///       <sin>
      ///         <amplitude_percent>0.0</amplitude_percent>
      ///         <period>1.0</period>
      ///       </sin>
      ///       <noise type="gaussian">
      ///         <mean>0.0</mean>
      ///         <stddev>0.1</stddev>
      ///       </noise>
      ///     </magnitude>
      ///     <direction>
      ///       <time_for_rise>1.0</time_for_rise>
      ///       <sin>
      ///         <amplitude>0.0</amplitude>
      ///         <period>1.0</period>
      ///       </sin>
      ///       <noise type="gaussian">
      ///         <mean>0.0</mean>
      ///         <stddev>0.1</stddev>
      ///       </noise>
      ///     </direction>
      ///   </horizontal>
      ///   <vertical>
      ///     <time_for_rise>1.0</time_for_rise>
      ///     <noise type="gaussian">
      ///       <mean>0.0</mean>
      ///       <stddev>0.1</stddev>
      ///     </noise>
      ///   </vertical>
      ///   <force_approximation_scaling_factor>
      ///     <when x_ge="-1" x_le="1" y_ge="-1" y_le="1" z_ge="-1" z_le="1">
      ///       <k>1.0</k>
      ///       <px>0 0 0 0</px>
      ///       <qy>0 0 0 0</qy>
      ///       <rz>0 0 0 0</rz>
      ///     </when>
      ///     <when x_gt="1" x_lt="2">1.0</when>
      ///     1.0
      ///   </force_approximation_scaling_factor>
      /// </plugin>
      /// \

      class GZ_SIM_VISIBLE WindTests final :
        public System,
        public ISystemConfigure,
        public ISystemPreUpdate
      {
        /// \brief Constructor
        public: WindTests(); // Changed from WindEffects

        /// \brief Destructor
        public: ~WindTests() override; // Changed from WindEffects

        // Documentation inherited
        public: void Configure(const Entity &_entity,
                               const std::shared_ptr<const sdf::Element> &_sdf,
                               EntityComponentManager &_ecm,
                               EventManager &_eventMgr) override;

        // Documentation inherited
        public: void PreUpdate(const UpdateInfo &_info,
                                EntityComponentManager &_ecm) override;

        /// \brief Private data pointer
        private: std::unique_ptr<WindTestsPrivate> dataPtr; // Changed from WindEffectsPrivate
      };
    }
  }
}

#endif