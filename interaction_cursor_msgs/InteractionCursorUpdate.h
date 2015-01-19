#ifndef _ROS_interaction_cursor_msgs_InteractionCursorUpdate_h
#define _ROS_interaction_cursor_msgs_InteractionCursorUpdate_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/PoseStamped.h"
#include "visualization_msgs/Marker.h"

namespace interaction_cursor_msgs
{

  class InteractionCursorUpdate : public ros::Msg
  {
    public:
      geometry_msgs::PoseStamped pose;
      uint8_t markers_length;
      visualization_msgs::Marker st_markers;
      visualization_msgs::Marker * markers;
      uint8_t button_state;
      uint8_t key_event;
      enum { NONE =  0  };
      enum { KEEP_ALIVE =  1  };
      enum { GRAB =  2  };
      enum { RELEASE =  3  };
      enum { QUERY_MENU =  4  };
      enum { KEY_UP =  1 };
      enum { KEY_DOWN =  2 };
      enum { KEY_LEFT =  3 };
      enum { KEY_RIGHT =  4 };
      enum { KEY_ENTER =  5 };
      enum { KEY_ESCAPE =  6 };

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->pose.serialize(outbuffer + offset);
      *(outbuffer + offset++) = markers_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < markers_length; i++){
      offset += this->markers[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->button_state >> (8 * 0)) & 0xFF;
      offset += sizeof(this->button_state);
      *(outbuffer + offset + 0) = (this->key_event >> (8 * 0)) & 0xFF;
      offset += sizeof(this->key_event);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->pose.deserialize(inbuffer + offset);
      uint8_t markers_lengthT = *(inbuffer + offset++);
      if(markers_lengthT > markers_length)
        this->markers = (visualization_msgs::Marker*)realloc(this->markers, markers_lengthT * sizeof(visualization_msgs::Marker));
      offset += 3;
      markers_length = markers_lengthT;
      for( uint8_t i = 0; i < markers_length; i++){
      offset += this->st_markers.deserialize(inbuffer + offset);
        memcpy( &(this->markers[i]), &(this->st_markers), sizeof(visualization_msgs::Marker));
      }
      this->button_state =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->button_state);
      this->key_event =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->key_event);
     return offset;
    }

    const char * getType(){ return "interaction_cursor_msgs/InteractionCursorUpdate"; };
    const char * getMD5(){ return "a43f17218e223e4570ef9a21571e18c1"; };

  };

}
#endif