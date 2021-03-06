/**
 * Licensed to Green Energy Corp (www.greenenergycorp.com) under one or
 * more contributor license agreements. See the NOTICE file distributed
 * with this work for additional information regarding copyright ownership.
 * Green Energy Corp licenses this file to you under the Apache License,
 * Version 2.0 (the "License"); you may not use this file except in
 * compliance with the License.  You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * This project was forked on 01/01/2013 by Automatak, LLC and modifications
 * may have been made to this file. Automatak, LLC licenses these modifications
 * to you under the terms of the License.
 */
#include "MasterStackImpl.h"

#include <openpal/IExecutor.h>

using namespace openpal;
using namespace opendnp3;

namespace asiodnp3
{

MasterStackImpl::MasterStackImpl(	LogRoot& root,
                                    IExecutor* apExecutor,
                                    ISOEHandler* apPublisher,
                                    IUTCTimeSource* apTimeSource,
                                    AsyncTaskGroup* apTaskGroup,
                                    const MasterStackConfig& config,
                                    const StackActionHandler& handler) :

	IMaster(root, apExecutor, config.app, config.link, handler),
	master(root, config.master, &appStack.application, apPublisher, apTaskGroup, apExecutor, apTimeSource)
{
	appStack.application.SetUser(&master);
}

ICommandProcessor* MasterStackImpl::GetCommandProcessor()
{
	return master.GetCommandProcessor();
}

MasterScan MasterStackImpl::AddClassScan(int aClassMask, openpal::TimeDuration aScanRate, openpal::TimeDuration aRetryRate)
{
	ExecutorPause pause(this->GetExecutor());
	return master.AddClassScan(aClassMask, aScanRate, aRetryRate);
}

MasterScan MasterStackImpl::GetIntegrityScan()
{
	return master.GetIntegrityScan();
}

}

