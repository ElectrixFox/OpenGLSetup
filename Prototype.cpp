struct Entity
{
	unsigned int ID;

	world* this_w;
};

template <typename Component_Type>
Component_Type& Get(Entity entity) { };

Component_Type& Get<Component_Type>(Entity entity)
{
	Component_Type& ct = GetComponentInList(entity);
}

template<typename type>
type GetComponentInList(Entity entity)
{
	type t = Convert<type>(GetList(TypeSpecificEnum, entity.world));
	return t;
}


#define C_LIST (void**)

template<typename Component_Type>
Component_Type Convert(C_LIST list) { };

template<>
Component_Type Convert<Component_Type>(C_LIST list)
{
	int size = ComponentSpecificEnum;
	Component_Type tempr_component;
	memcpy(&tempr_component, C_LIST, size);

	return tempr_component;
}

C_LIST GetList(enum Component__Type, world* world)
{
	return world->ecs.lists[Component__Type];
}
