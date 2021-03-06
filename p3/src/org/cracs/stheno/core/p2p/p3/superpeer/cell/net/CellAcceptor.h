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
 * File:   CellAceptor.h
 * Author: Rolando Martins (rolando.martins@gmail.com)
 *
 * Created on June 9, 2010, 12:58 PM
 */

#ifndef CELLACCEPTOR_H
#define	CELLACCEPTOR_H
#include "ace/Auto_Ptr.h"
#include "ace/Log_Msg.h"
#include "ace/INET_Addr.h"
#include "ace/SOCK_Acceptor.h"
#include "ace/Reactor.h"
#include <ace/Addr.h>
#include <euryale/net/PacketChannel.h>
#include <ace/Synch_Traits.h>
#include <ace/SOCK_Stream.h>
#include <euryale/threading/tpc/ThreadPerConnection.h>
//#include <stheno/core/p2p/p3/superpeer/cell/net/CellSvcHandler.h>

#include <euryale/net/endpoint/Endpoint.h>
#include <euryale/net/StreamChannelGroup.h>

class Cell;
class CellSvcHandler;

class CellAcceptor : public EventHandler, public CloseListener<ACE_SOCK_Stream, ACE_MT_SYNCH> {
public:
    CellAcceptor(Cell* cell,
                 ChannelManager<ACE_SOCK_Stream, ACE_MT_SYNCH>* group,
            ChannelManager<ACE_SOCK_Stream, ACE_MT_SYNCH>* followerGroup,
                 ChannelManager<ACE_SOCK_Stream, ACE_MT_SYNCH>* childrenGroup,
            ChannelManager<ACE_SOCK_Stream, ACE_MT_SYNCH>* leafGroup);
    virtual ~CellAcceptor();

    
    virtual int open(void *arg = 0) ;
    
    virtual int close();
    
    int open(EndpointPtr& endpointPtr) throw (EndpointException&,ExecutionModelException&);
    
    // Get this handler's I/O handle.
    virtual ACE_HANDLE get_handle(void) const;
    // Called when a connection is ready to accept.
    virtual int handle_input(ACE_HANDLE fd = ACE_INVALID_HANDLE);
    // Called when this handler is removed from the ACE_Reactor.
    virtual int handle_close(ACE_HANDLE handle,
            ACE_Reactor_Mask close_mask);
    //handle close of connection
    virtual void onClose(AbstractStreamChannel<ACE_SOCK_Stream, ACE_MT_SYNCH>* channel);
    //get SAP
    int getListenAddr(ACE_INET_Addr& addr);
    
    EndpointPtr& getEndpoint();
    
    
protected:
    ACE_Strong_Bound_Ptr<ThreadPerConnection, ACE_Recursive_Thread_Mutex>* m_tpcPrt;
    ChannelManager<ACE_SOCK_Stream, ACE_MT_SYNCH>* m_cellGroup;
    ChannelManager<ACE_SOCK_Stream, ACE_MT_SYNCH>* m_cellFollowerGroup;
    ChannelManager<ACE_SOCK_Stream, ACE_MT_SYNCH>* m_childrenGroup;
    ChannelManager<ACE_SOCK_Stream, ACE_MT_SYNCH>* m_leafGroup;    
    EndpointPtr m_endpointPtr;
    ACE_SOCK_Acceptor m_acceptor;
    Cell* m_cell;
};
#endif	/* CELLACEPTOR_H */

