#ifndef GUARD_median_h
#define GUARD_median_h

#include <vector>
#include <stdexcept>

//�����Ƕ���Զ���ķ��ͺ�����
//�����Զ���������ռ�MySpace�С�
//��Ҫʹ�õ���Щ������ʱ��
//�������ļ���ʼʹ�á�using MySpace::find;�������
//����ֱ���ں�����ǰ�ӡ�MySpace::����
namespace MySpace{

//����ʵ�ַ��ͺ���swap����������������ֵ 
template <class X>
void swap(X & x, X & y){
	X tmp=x;
	x=y;
	y=tmp;
}

//����ʵ�ַ��ͺ���sort����ð�ݷ����� 
template<class Ran>
void sort(Ran begin, Ran end)
{
//	std::cout << "sort...\n";
	for(Ran i=begin;i!=end;i++)
		for(Ran j=begin;j+1+(i-begin)!=end;j++)
			if(*j>*(j+1))
				swap(*j,*(j+1));
}

//����ʵ�ַ��ͺ���median������ֵ 
template<class T>
T median(std::vector<T> vec)
{
//	std::cout << "median...\n";
	typedef typename std::vector<T>::size_type vec_sz;
	vec_sz size = vec.size();
	if(size == 0)
		throw std::domain_error("median of an empty vector");
	sort(vec.begin(),vec.end());
	vec_sz mid = size/2;
	return size % 2 == 0 ? (vec[mid]+vec[mid-1])/2 : vec[mid];
}

//����ʵ�ַ��ͺ���average�����ֵ
template<class T>
T average(std::vector<T> vec)
{
	typename std::vector<T>::iterator iter=vec.begin();
	T sum=0.0;
	int num=0;
	
	for(;iter!=vec.end();iter++)
	{
		sum+=*iter;
		num++;
	}
	return sum/num;

//	std::cout << "average...\n";
	

}

//����ʵ�ַ��ͺ���find��ʵ�ֲ��ҹ��� 
template <class In, class X> 
In find(In begin, In end, const X&x){
	In iter=begin;
	while(iter!=end)
	{
		if(*iter==x)
			return iter;
		iter++;
	}
	return end;

//	std::cout << "find...\n";
	

}

//����ʵ�ַ��ͺ���remove_copy��
//��������x��ƥ���ԭ�ظ��Ƶ����������dest��ʾ��Ŀ���ַ�С� 
template <class In, class Out, class X> 
Out remove_copy(In begin, In end, Out dest,const X&x){
	In iter=begin;
	const Out itero=dest;
	while(iter!=end)
	{
		if((*iter)!=x)
		{
		
			*dest=*iter;
			dest++;
		}
		iter++;

	}
	return itero;

}

//����ʵ�ַ��ͺ���transform��
//�����������begin��end��ʾ�����е�Ԫ���ϵ��ú���f��
//������浽���������d��ʾ��Ŀ���ַ�С� 
template <class In, class Out, class F> 
Out transform(In begin,In end, Out dest, F func){

	const Out itero=dest;
	In iter=begin;

	while(iter!=end)
	{
		*dest=func(*iter);
		iter++;
		dest++;
	}

	
//	std::cout << "transform...\n";

	return itero;
}
	
}
#endif
