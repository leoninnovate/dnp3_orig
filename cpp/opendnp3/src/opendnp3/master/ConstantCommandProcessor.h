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
#ifndef __CONSTANT_COMMAND_PROCESSOR_H_
#define __CONSTANT_COMMAND_PROCESSOR_H_


#include "ICommandProcessor.h"


namespace openpal
{
class IExecutor;
}

namespace opendnp3
{

class ConstantCommandProcessor : public ICommandProcessor
{
public:

	ConstantCommandProcessor(openpal::IExecutor* apExecutor, const CommandResponse& response);

	// Implement the ICommandProcessor interface

	void SelectAndOperate(const ControlRelayOutputBlock& command, uint16_t index, ICommandCallback* pCallback);
	void DirectOperate(const ControlRelayOutputBlock& command, uint16_t index, ICommandCallback* pCallback);

	void SelectAndOperate(const AnalogOutputInt16& command, uint16_t index, ICommandCallback* pCallback);
	void DirectOperate(const AnalogOutputInt16& command, uint16_t index, ICommandCallback* pCallback);

	void SelectAndOperate(const AnalogOutputInt32& command, uint16_t index, ICommandCallback* pCallback);
	void DirectOperate(const AnalogOutputInt32& command, uint16_t index, ICommandCallback* pCallback);

	void SelectAndOperate(const AnalogOutputFloat32& command, uint16_t index, ICommandCallback* pCallback);
	void DirectOperate(const AnalogOutputFloat32& command, uint16_t index, ICommandCallback* pCallback);

	void SelectAndOperate(const AnalogOutputDouble64& command, uint16_t index, ICommandCallback* pCallback);
	void DirectOperate(const AnalogOutputDouble64& command, uint16_t index, ICommandCallback* pCallback);

private:

	void Respond(ICommandCallback* pCallback);

	openpal::IExecutor* pExecutor;
	CommandResponse response;
};

}

#endif

