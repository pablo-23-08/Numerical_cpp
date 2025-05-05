//~ #include "Ndarray.h"

Ndarray::Ndarray(const std::vector<size_t>& dimensions)
{
	form=dimensions;
	total_size=1;
	std::vector<size_t>::const_iterator it;
	for(it=dimensions.begin();it!=dimensions.end();++it)
	{
		total_size*=*it;
	}
    data.resize(total_size,0.0);
}

Ndarray Ndarray::arange(int size)
{
	size_t t=static_cast<size_t>(size);
	int i;
    Ndarray a({t});
    for(i=0;i<size;++i)
    {
        a.data[i]=static_cast<double>(i);
    }
    return a;
}

Ndarray Ndarray::array(const NDInitializer& init)
{
    if(init.data.empty())
    {
        std::cerr<<"ValueError:entrée de tableau vide"<<std::endl;
        exit(1);
    }
    Ndarray result(init.form);
    result.data = init.data;
    return result;
}

Ndarray Ndarray::reshape(const std::vector<size_t>& new_form)const
{
	size_t new_size;
    new_size=1;
	std::vector<size_t>::const_iterator it;
	for(it=new_form.begin();it!=new_form.end();++it)
	{
		new_size*=*it;
	}
    if(new_size!=total_size)
    {
		std::cerr<<"ValueError: cannot reshape array of size "<<total_size<<" into form [";
        for(size_t i=0;i<new_form.size();++i)
        {
            std::cerr<<new_form[i];
            if(i!=new_form.size()-1)
            {
                std::cerr<<",";
            }
        }
        std::cerr<<"]\n";
        exit(1);
    }
    Ndarray result(new_form);
    result.data=data;
    return result;
}

size_t Ndarray::get_index(const std::vector<size_t>& indices)const
{
    if(indices.size()!=form.size())
    {
        std::cerr<<"Nombre d'indices incorrect"<<std::endl;
        exit(1);
    }
    size_t index = 0;
    for(size_t i=0;i<indices.size();++i)
    {
        if(indices[i]>=form[i])
        {
            std::cerr<<"Indice hors limites"<<std::endl;
            exit(1);
        }
        size_t stride=1;
        for(size_t j=i+1;j<form.size();++j)
        {
            stride*=form[j];
        }
        index+=indices[i]*stride;
    }
    return index;
}

size_t Ndarray::get_max_width()const
{
    size_t max_width=1;
    for(size_t i=0;i<total_size;++i)
    {
        std::ostringstream flux;
        flux<<data[i];
        size_t width=flux.str().length();
        if(width>max_width)
        {
            max_width=width;
        }
    }
    return max_width;
}

void Ndarray::print_array(size_t offset, size_t dim, size_t indent, size_t width)const
{
	int extra_newlines;
    if(dim==form.size()-1)
    {
        std::cout<<"[";
        for(size_t i=0;i<form[dim];++i)
        {
            std::cout<< std::setw(width)<<data[offset+ i];
            if(i<form[dim]-1)std::cout<< " ";
        }
        std::cout<<"]";
    }
    else
    {
        std::cout<< "[";
        size_t stride=1;
        for(size_t i=dim+1;i<form.size();++i)
        {
            stride*=form[i];
        }
        for(size_t i=0;i<form[dim];++i)
        {
            if(i>0)
            {
                extra_newlines=form.size()-dim-2;
                if(extra_newlines>0){
                    std::cout<<std::string(extra_newlines,'\n');
                }
                std::cout<<std::string(indent+1,' ');
            }
            print_array(offset+i*stride,dim+1,indent+1,width);
            if(i<form[dim]-1)std::cout<<"\n";
        }
        std::cout<<"]";
	}
}

void Ndarray::print()const
{
    size_t max_width=get_max_width();
    print_array(0,0,0,max_width);
    std::cout<<"\n\n";
}

void Ndarray::shape()const
{
	std::cout<<"(";
	for(size_t i=0;i<form.size();++i)
    {
		std::cout<<form[i];
		if(i<form.size()-1)
			std::cout<<", ";
	}
	std::cout<<")\n\n";
}
