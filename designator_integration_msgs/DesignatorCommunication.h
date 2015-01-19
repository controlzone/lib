#ifndef _ROS_SERVICE_DesignatorCommunication_h
#define _ROS_SERVICE_DesignatorCommunication_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "designator_integration_msgs/DesignatorResponse.h"
#include "designator_integration_msgs/DesignatorRequest.h"

namespace designator_integration_msgs
{

static const char DESIGNATORCOMMUNICATION[] = "designator_integration_msgs/DesignatorCommunication";

  class DesignatorCommunicationRequest : public ros::Msg
  {
    public:
      designator_integration_msgs::DesignatorRequest request;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->request.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->request.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return DESIGNATORCOMMUNICATION; };
    const char * getMD5(){ return "bac4469d7aa87155670bba35ef4819f7"; };

  };

  class DesignatorCommunicationResponse : public ros::Msg
  {
    public:
      designator_integration_msgs::DesignatorResponse response;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->response.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->response.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return DESIGNATORCOMMUNICATION; };
    const char * getMD5(){ return "94f6e31f3e961c79934b2946cf3724ca"; };

  };

  class DesignatorCommunication {
    public:
    typedef DesignatorCommunicationRequest Request;
    typedef DesignatorCommunicationResponse Response;
  };

}
#endif
