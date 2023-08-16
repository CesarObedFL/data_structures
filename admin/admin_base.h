#ifndef ADMIN_BASE_H
#define ADMIN_BASE_H

class AdminBase {
    public:
        AdminBase() {}
        virtual void add() {}
        virtual void edit() {}
        virtual void erase() {}
        virtual bool save() {}
        virtual void details() {}
        virtual void list() {}
        virtual AdminBase &get_admin();
};

AdminBase& AdminBase::get_admin() {
    return *this;
}


#endif