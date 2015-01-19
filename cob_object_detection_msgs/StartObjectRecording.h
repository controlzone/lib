#ifndef _ROS_SERVICE_StartObjectRecording_h
#define _ROS_SERVICE_StartObjectRecording_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace cob_object_detection_msgs
{

static const char STARTOBJECTRECORDING[] = "cob_object_detection_msgs/StartObjectRecording";

  class StartObjectRecordingRequest : public ros::Msg
  {
    public:
      const char* object_label;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_object_label = strlen(this->object_label);
      memcpy(outbuffer + offset, &length_object_label, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->object_label, length_object_label);
      offset += length_object_label;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_object_label;
      memcpy(&length_object_label, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_object_label; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_object_label-1]=0;
      this->object_label = (char *)(inbuffer + offset-1);
      offset += length_object_label;
     return offset;
    }

    const char * getType(){ return STARTOBJECTRECORDING; };
    const char * getMD5(){ return "ed3bc845528a8aed5f5a16c86665300a"; };

  };

  class StartObjectRecordingResponse : public ros::Msg
  {
    public:

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return STARTOBJECTRECORDING; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class StartObjectRecording {
    public:
    typedef StartObjectRecordingRequest Request;
    typedef StartObjectRecordingResponse Response;
  };

}
#endif
