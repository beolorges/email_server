#ifndef CELL_EMAIL_HPP
#define CELL_EMAIL_HPP

class CellEmail{
    public:
        Email _data;
        CellEmail* _next;

    friend class stackEmail;
};

#endif