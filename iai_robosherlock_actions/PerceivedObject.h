#ifndef _ROS_iai_robosherlock_actions_PerceivedObject_h
#define _ROS_iai_robosherlock_actions_PerceivedObject_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/TransformStamped.h"
#include "shape_msgs/SolidPrimitive.h"

namespace iai_robosherlock_actions
{

  class PerceivedObject : public ros::Msg
  {
    public:
      const char* id;
      geometry_msgs::TransformStamped transform;
      shape_msgs::SolidPrimitive shape;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_id = strlen(this->id);
      memcpy(outbuffer + offset, &length_id, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->id, length_id);
      offset += length_id;
      offset += this->transform.serialize(outbuffer + offset);
      offset += this->shape.serialize(outbuffer + offset);
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
      offset += this->transform.deserialize(inbuffer + offset);
      offset += this->shape.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "iai_robosherlock_actions/PerceivedObject"; };
    const char * getMD5(){ return "a55c8e4e87fd41f6fcc459bb36f1f58d"; };

  };

}
#endif