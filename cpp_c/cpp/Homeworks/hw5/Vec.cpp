#include"Vec.h"
#include<memory>
template <class T>

Vec<T>& Vec<T>::operator=(const Vec& rhs){
    if(&rhs !=this){
        uncreate();
        create(rhs.begin(),rhs.end());
    }
    return this;
}   
template <class T> void Vec<T>::create()
{data=avail=limit=0;}

template <class T> void Vec<T>::create(size_type n,const T& val)
{
    data=alloc.allocate(n,0);
    limit=avail=data+n;
    std::uninitialized_fill(data,limit,val);

}
template <class T>
void Vec<T>::create(const_iterator i, const_iterator j)
{
    data=alloc.allocate(j-i);
    limit=avail=uninitialized_copy(i,j,data);
}
template <class T>
void Vec<T>::uncreate()
{
    if(data)
    {
        iterator it=avail;
        while(it!=data)
            alloc.destroy(--it);
        alloc.deallocate(data,limit-data);
    }
    data=avail=limit=0;
}
template <class T>
void Vec<T>::grow()
{
    size_type new_size =1;
    if(limit!=data) new_size=2*(limit-data);
    iterator new_data=alloc.allocate(new_size , 0);
    iterator new_avail=uninitialized_copy(data,avail,new_data);

    uncreate();
    data=new_data;
    avail=new_avail;
    limit=data+new_size;

}
template <class T>
void Vec<T>::unchecked_append(const T& val)
{
    alloc.construct(avail++,val);
}