#ifndef UTILITY_COMMUNICATIONRECEIVER_H_
#define UTILITY_COMMUNICATIONRECEIVER_H_

#include <string>
#include <zmq.hpp>
#include <utility/zhelpers.hpp>
#include <utility/LoggingUtility.h>


class CommunicationReceiver {
public:
	CommunicationReceiver(std::string ownerModule, std::string portIn, std::string envelope, int expNo);
	~CommunicationReceiver();
	std::pair<std::string, std::string> receive();
	std::string receiveFromHw();
	std::string receiveData();

private:
	std::string mOwnerModule;

	zmq::context_t* mContext;
	zmq::socket_t* mSubscriber;

	LoggingUtility* mLogger;

	std::string mEnvelope;
};

#endif
