#ifndef _ROS_sr_robot_msgs_reverseKinematics_h
#define _ROS_sr_robot_msgs_reverseKinematics_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace sr_robot_msgs
{

  class reverseKinematics : public ros::Msg
  {
    public:
      const char* finger_name;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_finger_name = strlen(this->finger_name);
      memcpy(outbuffer + offset, &length_finger_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->finger_name, length_finger_name);
      offset += length_finger_name;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_finger_name;
      memcpy(&length_finger_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_finger_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_finger_name-1]=0;
      this->finger_name = (char *)(inbuffer + offset-1);
      offset += length_finger_name;
     return offset;
    }

    const char * getType(){ return "sr_robot_msgs/reverseKinematics"; };
    const char * getMD5(){ return "db455ae8ce3e770363971b1e8e35fac4"; };

  };

}
#endif