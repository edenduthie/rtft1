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
 * File:   StartStreamPacket.h
 * Author: rmartins
 *
 * Created on November 17, 2010, 6:50 PM
 */

#ifndef STARTSTREAMSERVICEPACKET_H
#define	STARTSTREAMSERVICEPACKET_H

#include <stheno/core/p2p/net/packet/SthenoStreamPacket.h>
#include <euryale/common/uuid/UUID.h>
#include <euryale/net/endpoint/Endpoint.h>
//Frame size and rate is regulated by the service (specificed at creation time)
class StartStreamServicePacket : public SthenoStreamPacket {
public:    
    static const UShort START_STREAM_SERVICE_PACKET_OP = 0x8477;
    
    StartStreamServicePacket();
    StartStreamServicePacket(InputStream& inputStream);
    StartStreamServicePacket(ULong requestID,UUIDPtr& uuid, UUIDPtr& fid);
    virtual ~StartStreamServicePacket();

    virtual void
    serialize(OutputStream& outputStream) throw(SerializationException&);

    UUIDPtr& getUUID();
    UUIDPtr& getFID();

protected:
    UUIDPtr m_uuid;
    UUIDPtr m_fid;    

    virtual void
    serializeBody(OutputStream& outputStream) throw(SerializationException&);
    virtual void
    deserializeBody(InputStream& inputStream) throw(SerializationException&);
};


#endif	/* STARTSTREAMSERVICEPACKET_H */

