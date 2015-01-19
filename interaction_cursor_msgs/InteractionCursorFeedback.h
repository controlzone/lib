#ifndef _ROS_interaction_cursor_msgs_InteractionCursorFeedback_h
#define _ROS_interaction_cursor_msgs_InteractionCursorFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/PoseStamped.h"

namespace interaction_cursor_msgs
{

  class InteractionCursorFeedback : public ros::Msg
  {
    public:
      geometry_msgs::PoseStamped pose;
      uint8_t attachment_type;
      uint8_t event_type;
      enum { NONE =  0 };
      enum { POSITION =  1 };
      enum { ORIENTATION =  2 };
      enum { POSITION_AND_ORIENTATION =  3 };
      enum { GRABBED =  1 };
      enum { KEEP_ALIVE =  2 };
      enum { RELEASED =  3 };
      enum { LOST_GRASP =  4 };

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->pose.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->attachment_type >> (8 * 0)) & 0xFF;
      offset += sizeof(this->attachment_type);
      *(outbuffer + offset + 0) = (this->event_type >> (8 * 0)) & 0xFF;
      offset += sizeof(this->event_type);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->pose.deserialize(inbuffer + offset);
      this->attachment_type =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->attachment_type);
      this->event_type =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->event_type);
     return offset;
    }

    const char * getType(){ return "interaction_cursor_msgs/InteractionCursorFeedback"; };
    const char * getMD5(){ return "92dcfa34c8dfcb4f63d1d35ca54dc145"; };

  };

}
#endif