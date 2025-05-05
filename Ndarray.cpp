Ndarray::Ndarray(const std::vector<size_t>& dimensions)
{
	shape=dimensions;
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

Ndarray Ndarray::reshape(const std::vector<size_t>& new_shape)const
{
	size_t new_size;
    new_size=1;
	std::vector<size_t>::const_iterator it;
	for(it=new_shape.begin();it!=new_shape.end();++it)
	{
		new_size*=*it;
	}
    if(new_size!=total_size)
    {
		std::cerr<<"ValueError: cannot reshape array of size "<<total_size<<" into shape [";
        for (size_t i=0;i<new_shape.size();++i)
        {
            std::cerr<<new_shape[i];
            if(i!=new_shape.size()-1)
            {
                std::cerr<<",";
            }
        }
        std::cerr<<"]\n";
        exit(1);
    }
    Ndarray result(new_shape);
    result.data=data;
    return result;
}

size_t Ndarray::get_index(const std::vector<size_t>& indices)const
{
    if (indices.size()!=shape.size())
    {
        std::cerr<<"Nombre d'indices incorrect"<<std::endl;
        exit(1);
    }
    size_t index = 0;
    for (size_t i=0;i<indices.size();++i)
    {
        if(indices[i]>=shape[i])
        {
            std::cerr<<"Indice hors limites"<<std::endl;
            exit(1);
        }
        size_t stride=1;
        for(size_t j=i+1;j<shape.size();++j)
        {
            stride*=shape[j];
        }
        index+=indices[i]*stride;
    }
    return index;
}

size_t Ndarray::get_max_width()const
{
    size_t max_width=1;
    for (size_t i=0;i<total_size;++i)
    {
        std::ostringstream flux;
        flux<<data[i];
        size_t width=flux.str().length();
        if (width>max_width)
        {
            max_width=width;
        }
    }
    return max_width;
}

void Ndarray::print_array(size_t offset, size_t dim, size_t indent, size_t width)const
{
	int extra_newlines;
    if (dim==shape.size()-1)
    {
        std::cout<<"[";
        for (size_t i=0;i<shape[dim];++i)
        {
            std::cout<< std::setw(width)<<data[offset+ i];
            if(i<shape[dim]-1)std::cout<< " ";
        }
        std::cout<<"]";
    }
    else
    {
        std::cout<< "[";
        size_t stride=1;
        for(size_t i=dim+1;i<shape.size();++i)
        {
            stride*=shape[i];
        }
        for(size_t i=0;i<shape[dim];++i)
        {
            if(i>0)
            {
                extra_newlines=shape.size()-dim-2;
                if(extra_newlines>0){
                    std::cout<<std::string(extra_newlines,'\n');
                }
                std::cout<<std::string(indent+1,' ');
            }
            print_array(offset+i*stride,dim+1,indent+1,width);
            if(i<shape[dim]-1)std::cout<<"\n";
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
