#ifndef _ROS_carl_navigation_BlockedCells_h
#define _ROS_carl_navigation_BlockedCells_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Point.h"

namespace carl_navigation
{

  class BlockedCells : public ros::Msg
  {
    public:
      uint8_t blockedCells_length;
      geometry_msgs::Point st_blockedCells;
      geometry_msgs::Point * blockedCells;
      uint8_t edgeCells_length;
      geometry_msgs::Point st_edgeCells;
      geometry_msgs::Point * edgeCells;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = blockedCells_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < blockedCells_length; i++){
      offset += this->blockedCells[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset++) = edgeCells_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < edgeCells_length; i++){
      offset += this->edgeCells[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t blockedCells_lengthT = *(inbuffer + offset++);
      if(blockedCells_lengthT > blockedCells_length)
        this->blockedCells = (geometry_msgs::Point*)realloc(this->blockedCells, blockedCells_lengthT * sizeof(geometry_msgs::Point));
      offset += 3;
      blockedCells_length = blockedCells_lengthT;
      for( uint8_t i = 0; i < blockedCells_length; i++){
      offset += this->st_blockedCells.deserialize(inbuffer + offset);
        memcpy( &(this->blockedCells[i]), &(this->st_blockedCells), sizeof(geometry_msgs::Point));
      }
      uint8_t edgeCells_lengthT = *(inbuffer + offset++);
      if(edgeCells_lengthT > edgeCells_length)
        this->edgeCells = (geometry_msgs::Point*)realloc(this->edgeCells, edgeCells_lengthT * sizeof(geometry_msgs::Point));
      offset += 3;
      edgeCells_length = edgeCells_lengthT;
      for( uint8_t i = 0; i < edgeCells_length; i++){
      offset += this->st_edgeCells.deserialize(inbuffer + offset);
        memcpy( &(this->edgeCells[i]), &(this->st_edgeCells), sizeof(geometry_msgs::Point));
      }
     return offset;
    }

    const char * getType(){ return "carl_navigation/BlockedCells"; };
    const char * getMD5(){ return "ce735eafda11e266b368a3596d4632bf"; };

  };

}
#endif