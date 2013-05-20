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
 * File:   Executor.h
 * Author: rmartins
 *
 * Created on December 9, 2009, 3:10 PM
 */

#ifndef _EXECUTOR_H
#define	_EXECUTOR_H
class Request;

/*interface*/ class Executor {
public:
    Executor();    
    virtual ~Executor();
    virtual void execute(Request* request) = 0;
};

#endif	/* _EXECUTOR_H */

