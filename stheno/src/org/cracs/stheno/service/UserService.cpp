/*
 *  Copyright 2012 Rolando Martins, CRACS & INESC-TEC, DCC/FCUP
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *   
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 * 
 */
/* 
 * File:   Service.cpp
 * Author: Rolando Martins (rolando.martins@gmail.com)
 * 
 * Created on April 29, 2010, 2:48 PM
 */

#include "UserService.h"
#include "stheno/Stheno.h"

UserService::UserService(Stheno* runtime, const char* id) :
ServiceAbstract(id, ServiceAbstract::USER_TYPE),
m_runtime(runtime) {
}

UserService::UserService(Stheno* runtime, const char* id, UUIDPtr& iid) :
ServiceAbstract(id, iid, ServiceAbstract::USER_TYPE),
m_runtime(runtime) {
}

UserService::~UserService() {
    delete m_runtime;
}

Stheno* UserService::getRuntime() {
    return m_runtime;
}
