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
 * File:   VideoService.h
 * Author: Rolando Martins (rolando.martins@gmail.com)
 *
 * Created on May 8, 2010, 7:36 PM
 */

#ifndef VIDEOSERVICE_H
#define	VIDEOSERVICE_H

#include <stheno/service/Service.h>
#include <euryale/common/uuid/UUID.h>
#include <stheno/services/video/VideoQoS.h>

class Stheno;
class VideoService: public Service {
public:
    
    VideoService(const VideoService& orig);
    virtual ~VideoService();

    virtual void initVideoStream(UUID* sensorUUID,VideoQoS* qos){
        
    }
private:
    VideoService(SthenoPtr* runtime, OverlayPtr* overlay);
};

#endif	/* VIDEOSERVICE_H */

