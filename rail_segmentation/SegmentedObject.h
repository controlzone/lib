#ifndef _ROS_rail_segmentation_SegmentedObject_h
#define _ROS_rail_segmentation_SegmentedObject_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "sensor_msgs/PointCloud2.h"
#include "geometry_msgs/PoseStamped.h"

namespace rail_segmentation
{

  class SegmentedObject : public ros::Msg
  {
    public:
      sensor_msgs::PointCloud2 objectCloud;
      bool recognized;
      const char* name;
      int32_t model;
      uint8_t graspPoses_length;
      geometry_msgs::PoseStamped st_graspPoses;
      geometry_msgs::PoseStamped * graspPoses;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->objectCloud.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_recognized;
      u_recognized.real = this->recognized;
      *(outbuffer + offset + 0) = (u_recognized.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->recognized);
      uint32_t length_name = strlen(this->name);
      memcpy(outbuffer + offset, &length_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      union {
        int32_t real;
        uint32_t base;
      } u_model;
      u_model.real = this->model;
      *(outbuffer + offset + 0) = (u_model.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_model.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_model.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_model.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->model);
      *(outbuffer + offset++) = graspPoses_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < graspPoses_length; i++){
      offset += this->graspPoses[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->objectCloud.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_recognized;
      u_recognized.base = 0;
      u_recognized.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->recognized = u_recognized.real;
      offset += sizeof(this->recognized);
      uint32_t length_name;
      memcpy(&length_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
      union {
        int32_t real;
        uint32_t base;
      } u_model;
      u_model.base = 0;
      u_model.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_model.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_model.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_model.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->model = u_model.real;
      offset += sizeof(this->model);
      uint8_t graspPoses_lengthT = *(inbuffer + offset++);
      if(graspPoses_lengthT > graspPoses_length)
        this->graspPoses = (geometry_msgs::PoseStamped*)realloc(this->graspPoses, graspPoses_lengthT * sizeof(geometry_msgs::PoseStamped));
      offset += 3;
      graspPoses_length = graspPoses_lengthT;
      for( uint8_t i = 0; i < graspPoses_length; i++){
      offset += this->st_graspPoses.deserialize(inbuffer + offset);
        memcpy( &(this->graspPoses[i]), &(this->st_graspPoses), sizeof(geometry_msgs::PoseStamped));
      }
     return offset;
    }

    const char * getType(){ return "rail_segmentation/SegmentedObject"; };
    const char * getMD5(){ return "1f57a1aa2521ed1b4a21a294655fff5e"; };

  };

}
#endif