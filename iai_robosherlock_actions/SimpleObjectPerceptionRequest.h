#ifndef _ROS_iai_robosherlock_actions_SimpleObjectPerceptionRequest_h
#define _ROS_iai_robosherlock_actions_SimpleObjectPerceptionRequest_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace iai_robosherlock_actions
{

  class SimpleObjectPerceptionRequest : public ros::Msg
  {
    public:
      const char* id;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_id = strlen(this->id);
      memcpy(outbuffer + offset, &length_id, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->id, length_id);
      offset += length_id;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_id;
      memcpy(&length_id, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_id-1]=0;
      this->id = (char *)(inbuffer + offset-1);
      offset += length_id;
     return offset;
    }

    const char * getType(){ return "iai_robosherlock_actions/SimpleObjectPerceptionRequest"; };
    const char * getMD5(){ return "bbfcda76036ebbe3d36caf7af80b260c"; };

  };

}
#endif