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
 * File:   StreamChannelClient.cpp
 * Author: rmartins
 * 
 * Created on October 27, 2010, 10:30 AM
 */

#include "StreamChannelClient.h"

StreamChannelClient::~StreamChannelClient() {
}

StreamChannelClient::StreamChannelClient() :
SuperType() {
    throw -1;
}

StreamChannelClient::StreamChannelClient(
        StreamChannelPacketFactory* factory,
        UUIDPtr& uuid, UUIDPtr& fid, QoSEndpoint& qosE,
        NetReservation* reserve,
        NetQoS* qos) :
SuperType(factory, reserve, qos)//,m_uuid(uuid),m_fid(fid),m_qosE(qosE)
{
    m_uuid = uuid;
    m_fid = fid;
    m_channelQoS = qosE;

}

/*StreamChannelClient::StreamChannelClient(
        StreamChannelPacketFactory* factory,
        UUIDPtr& uuid, UUIDPtr& fid, QoSEndpoint& qosE,
        PacketHandler* readHandler,
        AsyncPacketWriterHandler* writeHandler,
        bool asyncRead, bool asyncWrite,
        ExecutionModelPtr* ec,
        NetReservation* reserve,
        NetQoS* qos,
        CloseListenerType* closeListener) :
SuperType(factory, readHandler, writeHandler, asyncRead, asyncWrite, ec, reserve, qos, closeListener)//,
//m_uuid(uuid),m_fid(fid),m_qosE(qosE)
{
    m_uuid = uuid;
    m_fid = fid;
    m_channelQoS = qosE;

}*/

StreamChannelClient::StreamChannelClient(
        StreamChannelPacketFactory* factory,
        UUIDPtr& uuid, UUIDPtr& fid, QoSEndpoint& qosE,
        PacketHandler* readHandler,
        bool asyncWrite,
        ExecutionModelPtr* ec,
        NetReservation* reserve,
        NetQoS* qos,
        CloseListenerType* closeListener) :
SuperType(factory, readHandler, asyncWrite, ec, reserve, qos, closeListener)
{
    m_uuid = uuid;
    m_fid = fid;
    m_channelQoS = qosE;

}



