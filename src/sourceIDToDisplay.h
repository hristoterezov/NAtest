struct Area {
    int x;
    int y;
    int width;
    int height;
    Area(): x(0), y(0), width(0), height(0) {};
};

bool sourceIDToDisplayF(int sourceID, Area* res);
