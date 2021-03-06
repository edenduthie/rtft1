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
 * File:   FTDataReplicationPacket.h
 * Author: rmartins
 *
 * Created on November 27, 2010, 5:26 PM
 */

#ifndef FTDATAREPLICATIONPACKET_H
#define	FTDATAREPLICATIONPACKET_H

#include <stheno/core/p2p/net/packet/SthenoStreamPacket.h>
#include <euryale/common/uuid/UUID.h>
#include <stheno/service/ServiceParams.h>

class FTDataReplicationPacket : public SthenoStreamPacket {
public:
    static const UShort DATA_REPLICATION_PACKET_OP = 0x5871;
    FTDataReplicationPacket();
    FTDataReplicationPacket(InputStream& inputStream);
    FTDataReplicationPacket(
            ULong requestID,
            ACE_Message_Block* mb);
    virtual ~FTDataReplicationPacket();

    virtual void
    serialize(OutputStream& outputStream) throw (SerializationException&);

    ACE_Message_Block* getPayload();
    
protected:
    ACE_Message_Block* m_payload;

    virtual void
    serializeBody(OutputStream& outputStream) throw (SerializationException&);
    virtual void
    deserializeBody(InputStream& inputStream) throw (SerializationException&);
};


#endif	/* FTDATAREPLICATIONPACKET_H */

