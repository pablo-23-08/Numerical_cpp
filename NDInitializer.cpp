//~ #include "NDInitializer.h"
NDInitializer::NDInitializer(std::initializer_list<double>list)
{
	data=list;
    form.push_back(list.size());
}

NDInitializer::NDInitializer(std::initializer_list<NDInitializer>list)
{
    size_t expected_size;
    const NDInitializer& first=*list.begin();
    form=first.form;
    form.insert(form.begin(),list.size());
	expected_size=first.data.size();
    for(const NDInitializer& init:list)
    {
        if(init.data.size()!=expected_size)
        {
            std::cerr<<"ValueError:définition d'un élément de tableau avec une séquence. Le tableau demandé présente une forme inhomogène après une dimension."<<std::endl;
            exit(1);
        }
        data.insert(data.end(),init.data.begin(),init.data.end());
    }
}
