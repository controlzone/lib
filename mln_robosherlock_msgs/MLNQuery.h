#ifndef _ROS_SERVICE_MLNQuery_h
#define _ROS_SERVICE_MLNQuery_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "mln_robosherlock_msgs/MLNAtoms.h"

namespace mln_robosherlock_msgs
{

static const char MLNQUERY[] = "mln_robosherlock_msgs/MLNQuery";

  class MLNQueryRequest : public ros::Msg
  {
    public:
      uint8_t mln_atoms_length;
      mln_robosherlock_msgs::MLNAtoms st_mln_atoms;
      mln_robosherlock_msgs::MLNAtoms * mln_atoms;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = mln_atoms_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < mln_atoms_length; i++){
      offset += this->mln_atoms[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t mln_atoms_lengthT = *(inbuffer + offset++);
      if(mln_atoms_lengthT > mln_atoms_length)
        this->mln_atoms = (mln_robosherlock_msgs::MLNAtoms*)realloc(this->mln_atoms, mln_atoms_lengthT * sizeof(mln_robosherlock_msgs::MLNAtoms));
      offset += 3;
      mln_atoms_length = mln_atoms_lengthT;
      for( uint8_t i = 0; i < mln_atoms_length; i++){
      offset += this->st_mln_atoms.deserialize(inbuffer + offset);
        memcpy( &(this->mln_atoms[i]), &(this->st_mln_atoms), sizeof(mln_robosherlock_msgs::MLNAtoms));
      }
     return offset;
    }

    const char * getType(){ return MLNQUERY; };
    const char * getMD5(){ return "6691dd4bac3d071ff782dce66f65b45d"; };

  };

  class MLNQueryResponse : public ros::Msg
  {
    public:
      uint8_t result_length;
      char* st_result;
      char* * result;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = result_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < result_length; i++){
      uint32_t length_resulti = strlen(this->result[i]);
      memcpy(outbuffer + offset, &length_resulti, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->result[i], length_resulti);
      offset += length_resulti;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t result_lengthT = *(inbuffer + offset++);
      if(result_lengthT > result_length)
        this->result = (char**)realloc(this->result, result_lengthT * sizeof(char*));
      offset += 3;
      result_length = result_lengthT;
      for( uint8_t i = 0; i < result_length; i++){
      uint32_t length_st_result;
      memcpy(&length_st_result, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_result; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_result-1]=0;
      this->st_result = (char *)(inbuffer + offset-1);
      offset += length_st_result;
        memcpy( &(this->result[i]), &(this->st_result), sizeof(char*));
      }
     return offset;
    }

    const char * getType(){ return MLNQUERY; };
    const char * getMD5(){ return "d671534a9998964137887d0b28abf896"; };

  };

  class MLNQuery {
    public:
    typedef MLNQueryRequest Request;
    typedef MLNQueryResponse Response;
  };

}
#endif
