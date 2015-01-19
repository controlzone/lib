#ifndef _ROS_rail_segmentation_SegmentedObjectList_h
#define _ROS_rail_segmentation_SegmentedObjectList_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "rail_segmentation/SegmentedObject.h"

namespace rail_segmentation
{

  class SegmentedObjectList : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint8_t objects_length;
      rail_segmentation::SegmentedObject st_objects;
      rail_segmentation::SegmentedObject * objects;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset++) = objects_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < objects_length; i++){
      offset += this->objects[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint8_t objects_lengthT = *(inbuffer + offset++);
      if(objects_lengthT > objects_length)
        this->objects = (rail_segmentation::SegmentedObject*)realloc(this->objects, objects_lengthT * sizeof(rail_segmentation::SegmentedObject));
      offset += 3;
      objects_length = objects_lengthT;
      for( uint8_t i = 0; i < objects_length; i++){
      offset += this->st_objects.deserialize(inbuffer + offset);
        memcpy( &(this->objects[i]), &(this->st_objects), sizeof(rail_segmentation::SegmentedObject));
      }
     return offset;
    }

    const char * getType(){ return "rail_segmentation/SegmentedObjectList"; };
    const char * getMD5(){ return "98e61791b4e87705ed0f94067375c539"; };

  };

}
#endif