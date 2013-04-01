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
 * File:   Request.h
 * Author: rmartins
 *
 * Created on December 9, 2009, 12:20 PM
 */

#ifndef _REQUEST_H
#define	_REQUEST_H

class Request {
public:
    Request();    
    virtual ~Request();

    /// if request is a sucess
    virtual void onSucess(){}
    /// on request error
    virtual void onError(){}
private:

};

#endif	/* _REQUEST_H */
