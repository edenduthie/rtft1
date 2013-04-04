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
 * File:   P3PeerMap.h
 * Author: rmartins
 *
 * Created on June 18, 2010, 5:45 PM
 */

#ifndef P3PEERMAP_H
#define	P3PEERMAP_H

#include <stheno/core/p2p/common/PeerMap.h>
#include <stheno/core/p2p/p3/common/P3PeerInfo.h>


class P3PeerMap: public PeerMapBase<P3PeerInfo> {
public:
    P3PeerMap();    
    virtual ~P3PeerMap();
};

#endif	/* P3PEERMAP_H */

