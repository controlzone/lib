#ifndef _ROS_cob_object_detection_msgs_TrainObjectGoal_h
#define _ROS_cob_object_detection_msgs_TrainObjectGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace cob_object_detection_msgs
{

  class TrainObjectGoal : public ros::Msg
  {
    public:
      const char* object_name;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_object_name = strlen(this->object_name);
      memcpy(outbuffer + offset, &length_object_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->object_name, length_object_name);
      offset += length_object_name;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_object_name;
      memcpy(&length_object_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_object_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_object_name-1]=0;
      this->object_name = (char *)(inbuffer + offset-1);
      offset += length_object_name;
     return offset;
    }

    const char * getType(){ return "cob_object_detection_msgs/TrainObjectGoal"; };
    const char * getMD5(){ return "2f12226348d323c2e5b2031b3da53f1b"; };

  };

}
#endif