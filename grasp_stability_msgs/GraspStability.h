#ifndef _ROS_grasp_stability_msgs_GraspStability_h
#define _ROS_grasp_stability_msgs_GraspStability_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace grasp_stability_msgs
{

  class GraspStability : public ros::Msg
  {
    public:
      const char* measurement_context_id;
      float grasp_quality;
      float estimation_confidence;
      int32_t grasp_category;
      enum { GRASP_CAT_UNDEFINED = 0 };
      enum { GRASP_CAT_GOOD = 1 };
      enum { GRASP_CAT_MEDIUM = 2 };
      enum { GRASP_CAT_BAD = 3 };

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_measurement_context_id = strlen(this->measurement_context_id);
      memcpy(outbuffer + offset, &length_measurement_context_id, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->measurement_context_id, length_measurement_context_id);
      offset += length_measurement_context_id;
      union {
        float real;
        uint32_t base;
      } u_grasp_quality;
      u_grasp_quality.real = this->grasp_quality;
      *(outbuffer + offset + 0) = (u_grasp_quality.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_grasp_quality.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_grasp_quality.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_grasp_quality.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->grasp_quality);
      union {
        float real;
        uint32_t base;
      } u_estimation_confidence;
      u_estimation_confidence.real = this->estimation_confidence;
      *(outbuffer + offset + 0) = (u_estimation_confidence.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_estimation_confidence.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_estimation_confidence.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_estimation_confidence.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->estimation_confidence);
      union {
        int32_t real;
        uint32_t base;
      } u_grasp_category;
      u_grasp_category.real = this->grasp_category;
      *(outbuffer + offset + 0) = (u_grasp_category.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_grasp_category.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_grasp_category.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_grasp_category.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->grasp_category);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_measurement_context_id;
      memcpy(&length_measurement_context_id, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_measurement_context_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_measurement_context_id-1]=0;
      this->measurement_context_id = (char *)(inbuffer + offset-1);
      offset += length_measurement_context_id;
      union {
        float real;
        uint32_t base;
      } u_grasp_quality;
      u_grasp_quality.base = 0;
      u_grasp_quality.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_grasp_quality.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_grasp_quality.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_grasp_quality.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->grasp_quality = u_grasp_quality.real;
      offset += sizeof(this->grasp_quality);
      union {
        float real;
        uint32_t base;
      } u_estimation_confidence;
      u_estimation_confidence.base = 0;
      u_estimation_confidence.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_estimation_confidence.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_estimation_confidence.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_estimation_confidence.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->estimation_confidence = u_estimation_confidence.real;
      offset += sizeof(this->estimation_confidence);
      union {
        int32_t real;
        uint32_t base;
      } u_grasp_category;
      u_grasp_category.base = 0;
      u_grasp_category.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_grasp_category.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_grasp_category.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_grasp_category.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->grasp_category = u_grasp_category.real;
      offset += sizeof(this->grasp_category);
     return offset;
    }

    const char * getType(){ return "grasp_stability_msgs/GraspStability"; };
    const char * getMD5(){ return "27f85b330ae8a5e5c97d0bc8c3a83f4a"; };

  };

}
#endif