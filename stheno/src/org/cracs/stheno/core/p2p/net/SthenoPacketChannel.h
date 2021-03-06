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
 * File:   SthenoPacketChannel.h
 * Author: Rolando Martins (rolando.martins@gmail.com)
 *
 * Created on May 4, 2010, 5:05 PM
 */

#ifndef STHENOPACKETCHANNEL_H
#define	STHENOPACKETCHANNEL_H

#include <euryale/net/PacketChannel.h>
#include <stheno/core/p2p/net/SthenoPacketFactory.h>
#include <stheno/core/p2p/net/packet/SthenoPacket.h>

//CHANNEL = TRANSPORT

template <class SOCK_TYPE, class SYNC_TYPE>
class SthenoPacketChannel: public PacketChannel<SthenoPacket,SthenoHeader,
        SthenoPacketFactory, SOCK_TYPE, SYNC_TYPE>{
public:
    SthenoPacketChannel(){}
    virtual ~SthenoPacketChannel(){}
protected:

};

#endif	/* STHENOPACKETCHANNEL_H */

