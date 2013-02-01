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
 * File:   FTRemoveReplicaReplyPacket.h
 * Author: rmartins
 *
 * Created on November 27, 2010, 6:30 PM
 */

#ifndef FTREMOVEREPLICAREPLYPACKET_H
#define	FTREMOVEREPLICAREPLYPACKET_H

#include <stheno/core/p2p/net/packet/SthenoStreamPacket.h>
#include <euryale/common/uuid/UUID.h>

class FTRemoveReplicaReplyPacket : public SthenoStreamPacket {
public:

    static const UShort REMOVE_REPLICA_REPLY_PACKET_OP = 0x0873;
    FTRemoveReplicaReplyPacket();
    FTRemoveReplicaReplyPacket(InputStream& inputStream);
    FTRemoveReplicaReplyPacket(ULong packetID, UInt packetIDReply, bool acception);
    virtual ~FTRemoveReplicaReplyPacket();

    virtual void serialize(OutputStream& outputStream) THROW(SerializationException&);

    bool getJoinResult();
    ULong getPacketReplyID();

protected:
    ULong m_packetIDReply;
    Boolean m_acception;

    virtual void
    serializeBody(OutputStream& outputStream) THROW(SerializationException&);
    virtual void
    deserializeBody(InputStream& inputStream) THROW(SerializationException&);
};


#endif	/* FTREMOVEREPLICAREPLYPACKET_H */

