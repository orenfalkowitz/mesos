/**
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "slave/constants.hpp"

namespace mesos {
namespace internal {
namespace slave {

const Duration EXECUTOR_REGISTRATION_TIMEOUT = Minutes(1.0);
const Duration EXECUTOR_SHUTDOWN_GRACE_PERIOD = Seconds(5.0);
const Duration EXECUTOR_REREGISTER_TIMEOUT = Seconds(2.0);
const Duration STATUS_UPDATE_RETRY_INTERVAL = Seconds(10.0);
const Duration GC_DELAY = Weeks(1.0);
const Duration DISK_WATCH_INTERVAL = Minutes(1.0);
const Duration RESOURCE_MONITORING_INTERVAL = Seconds(5.0);
const uint32_t MAX_COMPLETED_FRAMEWORKS = 50;
const uint32_t MAX_COMPLETED_EXECUTORS_PER_FRAMEWORK = 150;
const uint32_t MAX_COMPLETED_TASKS_PER_EXECUTOR = 200;
const double DEFAULT_CPUS = 1;
const double DEFAULT_MEM = 1024; // In MB.
const double DEFAULT_DISK = 10240; // In MB.
const std::string DEFAULT_PORTS = "[31000-32000]";

} // namespace slave {
} // namespace internal {
} // namespace mesos {
