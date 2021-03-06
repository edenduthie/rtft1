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
 * File:   RebindMeshPacket.h
 * Author: rmartins
 *
 * Created on September 3, 2010, 12:16 PM
 */

#ifndef REBINDMESHPACKET_H
#define	REBINDMESHPACKET_H

#include <stheno/core/p2p/net/packet/SthenoPacket.h>
#include <stheno/core/p2p/p3/superpeer/cell/CellID.h>
#include <stheno/core/p2p/p3/superpeer/cell/net/packet/CellPacketTypes.h>
#include <euryale/net/endpoint/Endpoint.h>
#include <euryale/net/endpoint/SAPInfo.h>

class RebindMeshPacket : public SthenoPacket {
public:

    RebindMeshPacket(UUIDPtr& srcPID,
            UUIDPtr& srcFID,
            UUIDPtr& dstPID,
            UUIDPtr& dstFID,
            ULong requestID,
            int peerType,
            UUIDPtr& uuid,
            CellIDPtr& cellID,
            CellIDPtr& parentCellID,
            EndpointPtr& endpoint,
            EndpointPtr& followerEndpoint,
            SAPInfoPtr& discoverySAP,
            SAPInfoPtr& meshSAP,
            SAPInfoPtr& ftSAP,
            ACE_Message_Block* state) : SthenoPacket(srcPID, srcFID, dstPID, dstFID, REBIND_MESH_PACKET, requestID),
    m_parentCellID(parentCellID),
    m_type(peerType),
    m_uuid(uuid),
    m_cellID(cellID),
    m_endpoint(endpoint),
    m_discoverySAP(discoverySAP),
    m_meshSAP(meshSAP),
    m_ftSAP(ftSAP),
    m_state(state) {
    }

    RebindMeshPacket() : SthenoPacket(), m_state(0) {
    }

    virtual ~RebindMeshPacket();

    virtual void serialize(OutputStream& outputStream) THROW(SerializationException&) {
        UInt bodySize = getBodySerializationSize();
        ((SthenoHeader*) m_packetHeader)->m_messageSize = bodySize;
        serializeHeader(outputStream);
        serializeBody(outputStream);
    }

    CellIDPtr& getParentCellID() {
        return m_parentCellID;
    }

    SAPInfoPtr& getDiscoverySAP() {
        return m_discoverySAP;
    }

    SAPInfoPtr& getMeshSAP() {
        return m_meshSAP;
    }

    SAPInfoPtr& getFTSAP() {
        return m_ftSAP;
    }

    UUIDPtr& getUUID() {
        return m_uuid;
    }

    CellIDPtr& getCellID() {
        return m_cellID;
    }

    EndpointPtr& getEndpoint() {
        return m_endpoint;
    }
    
    EndpointPtr& getFollowerEndpoint() {
        return m_followerEndpoint;
    }

    int getType() {
        return m_type;
    }

    ACE_Message_Block* deattachState() {
        ACE_Message_Block* state = m_state;
        m_state = 0;
        return state;
    }

protected:
    UUIDPtr m_uuid;
    CellIDPtr m_cellID;
    CellIDPtr m_parentCellID;
    EndpointPtr m_endpoint;
    EndpointPtr m_followerEndpoint;
    SAPInfoPtr m_discoverySAP;
    SAPInfoPtr m_meshSAP;
    SAPInfoPtr m_ftSAP;
    int m_type;
    ACE_Message_Block* m_state;
    //JoinPeer m_joinPeer;

    virtual void
    serializeBody(OutputStream& outputStream) THROW(SerializationException&) {
        //m_joinPeer.serialize(outputStream);
        outputStream.write_long(m_type);
        m_uuid->serialize(outputStream);
        m_cellID->serialize(outputStream);
        m_parentCellID->serialize(outputStream);
        if (!m_endpoint.null()) {
            Boolean flag = true;
            outputStream.write_boolean(flag);
            m_endpoint->serialize(outputStream);
        } else {
            outputStream.write_boolean(false);
        }
        
        if (!m_followerEndpoint.null()) {
            Boolean flag = true;
            outputStream.write_boolean(flag);
            m_followerEndpoint->serialize(outputStream);
        } else {
            outputStream.write_boolean(false);
        }
        
        if (!m_discoverySAP.null()) {
            Boolean flag = true;
            outputStream.write_boolean(flag);
            m_discoverySAP->serialize(outputStream);
        } else {
            outputStream.write_boolean(false);
        }
        
        if (!m_meshSAP.null()) {
            Boolean flag = true;
            outputStream.write_boolean(flag);
            m_meshSAP->serialize(outputStream);
        } else {
            outputStream.write_boolean(false);
        }
        
        if (!m_ftSAP.null()) {
            Boolean flag = true;
            outputStream.write_boolean(flag);
            m_ftSAP->serialize(outputStream);
        } else {
            outputStream.write_boolean(false);
        }

        if (m_state != 0) {
            outputStream.write_boolean(true);
            UInt size = m_state->total_length();
            outputStream.write_ulong(size);
            outputStream.write_octet_array_mb(m_state);
        } else {
            outputStream.write_boolean(false);
        }

    }

    virtual void
    deserializeBody(InputStream& inputStream) THROW(SerializationException&) {
        //m_joinPeer.deserialize(inputStream);
        inputStream.read_long(m_type);
        UUID* uuid = new UUID(inputStream);
        m_uuid.reset(uuid);
        CellID* cellID = new CellID(inputStream);
        m_cellID.reset(cellID);
        CellID* parentCellID = new CellID(inputStream);
        m_parentCellID.reset(parentCellID);
        Boolean flag = false;
        inputStream.read_boolean(flag);
        if (flag) {
            Endpoint* endpoint = new Endpoint(inputStream);
            m_endpoint.reset(endpoint);
        }
        inputStream.read_boolean(flag);
        if (flag) {
            Endpoint* endpoint = new Endpoint(inputStream);
            m_followerEndpoint.reset(endpoint);
        }
        inputStream.read_boolean(flag);
        if (flag) {
            SAPInfo* info = new SAPInfo(inputStream);
            m_discoverySAP.reset(info);
        }
        
        inputStream.read_boolean(flag);
        if (flag) {
            SAPInfo* info = new SAPInfo(inputStream);
            m_meshSAP.reset(info);
        }
        
        inputStream.read_boolean(flag);
        if (flag) {
            SAPInfo* info = new SAPInfo(inputStream);
            m_ftSAP.reset(info);
        }

        inputStream.read_boolean(flag);
        if (flag) {
            UInt count = 0;
            inputStream.read_ulong(count);
            if (m_state != 0) {
                ACE_Message_Block::release(m_state);
                m_state = 0;
            }
            m_state = new ACE_Message_Block(count);
            inputStream.read_octet_array((Octet*) m_state->base(), count);
            m_state->wr_ptr(count);
        }
    }
};

#endif	/* REBINDMESHPACKET_H */

