#ifndef SWIG_CGAL_SPATIAL_SEARCHING_NN_SEARCH_H
#define SWIG_CGAL_SPATIAL_SEARCHING_NN_SEARCH_H

#include <SWIG_CGAL/Common/Macros.h>
#include <SWIG_CGAL/Common/Input_iterator.h>


DECLARE_ITERATOR_CLASS_2(iterator,NN_search_iterator)

template <class Cpp_base,class Query,class Tree>
class NN_search_wrapper
{
  Cpp_base data;
public:
  #ifndef SWIG
  typedef Cpp_base cpp_base;
  #endif

  typedef typename Tree::Point_d Point_d;
  typedef std::pair<Point_d,double>  Point_with_transformed_distance;
  typedef NN_search_iterator<Cpp_base,Point_with_transformed_distance> Iterator;
//Creation
  NN_search_wrapper(Tree& tree,const Query& query):data(tree.get_data_ref(),query.get_data()){}
  NN_search_wrapper(Tree& tree,const Query& query,int k):data(tree.get_data_ref(),query.get_data(),k){}
  NN_search_wrapper(Tree& tree,const Query& query,int k,double eps):data(tree.get_data_ref(),query.get_data(),k,eps){}
  NN_search_wrapper(Tree& tree,const Query& query,int k,double eps,bool search_nearest):data(tree.get_data_ref(),query.get_data(),k,eps,search_nearest){}
//Operations
  Iterator iterator() {
    return Iterator(data.begin(),data.end());
  }
};

template <class Cpp_base,class Query,class Tree>
class NN_search_wrapper_incremental
{
  Cpp_base data;
public:
  #ifndef SWIG
  typedef Cpp_base cpp_base;
  #endif
  typedef typename Tree::Point_d Point_d;
  typedef std::pair<Point_d,double>  Point_with_transformed_distance;
  typedef NN_search_iterator<Cpp_base,Point_with_transformed_distance> Iterator;
//Creation
  NN_search_wrapper_incremental(Tree& tree,const Query& query):data(tree.get_data_ref(),query.get_data()){}
  NN_search_wrapper_incremental(Tree& tree,const Query& query,double eps):data(tree.get_data_ref(),query.get_data(),eps){}
  NN_search_wrapper_incremental(Tree& tree,const Query& query,double eps,bool search_nearest):data(tree.get_data_ref(),query.get_data(),eps,search_nearest){}
//Operations
  Iterator iterator() {
    return Iterator(data.begin(),data.end());
  }
  
  Point_d value(){
    typename Cpp_base::iterator it=data.begin();
    Point_d ret (( it )->first);
    ++it;
    return ret;
    
  }
};


#endif //SWIG_CGAL_SPATIAL_SEARCHING_NN_SEARCH_H

//Operations
// std::ostream&  s.statistics ( std::ostream& s)  Inserts statistics of the search process into the output stream s. 