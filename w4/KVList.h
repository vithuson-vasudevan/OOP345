#ifndef _KVList_H_
#define _KVList_H_
//includes
#include <cstddef>

template<typename K,typename V, int N = 0>
class KVList{
	  K name[N];
	  V values[N];
	  size_t count;
	public:
		   KVList(){
				 count = 0;
		    }
		    size_t size() const{
			        return count;
		    }
		    const K& key(int i) const{
			        if (i<count)
				            return name[i];
		    }
		    const V& value(int i) const{
			        if (i < count)
					        return values[i];
		    }
		    KVList& add(const K& kk, const V& vv){
					 if (count < N){
					         name[count] = kk;
					         values[count] = vv;
					         count++;
					}
				     return *this;
		    }

		    int find(const K& kk) const{
		            for (int i = 0; i < count;i++){
					          if(name[i]== kk)
			                         return  i;
			                  }
					return 0;
		     }
			KVList& replace(int i, const K& k, const V& v){
			        if(i<count){
						name[i] = k;
			            values[i]=v;
			       }
					return *this;
			}
};
#endif

