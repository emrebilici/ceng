void midpointLine(double x1, double x0, double y1, double y0, Vec3 color0, Vec3 color1, Camera cam ) {
        double alpha;
        double slope = (y1 - y0) / (x1 - x0);
        if (slope >= 1) {
                int x = x0;
                double d = 2*(x0 - x1) + y1 - y0;
                for (int y = y0; y <= y1; y++){
                        alpha = (x - x0) / (x1 - x0);

                        double cx = color0.x * (1 - alpha) + alpha * color1.x;
                        double cy = color0.y * (1 - alpha) + alpha * color1.y;
                        double cz = color0.z * (1 - alpha) + alpha * color1.z;

                        if (x > 0 && y > 0 && cam.sizeX > x && cam.sizeY > y){
                                image[x][y].r = (int)cx;
                                image[x][y].g = (int)cy;
                                image[x][y].b = (int)cz;
                        }

                        if (d < 0){
                                x++;
                                d += 2*(x0 - x1 + y1 - y0);
                        }
                        else{
                                d += 2*(x0 - x1);
                        }
                }
        }
        else if (slope > 0 ) {
                int y = y0;
                double d = 2*(y0 - y1) + x1 - x0;
                for (int x = x0; x <= x1; x++){
                        alpha = (x - x0) / (x1 - x0);

                        double cx = color0.x * (1 - alpha) + alpha * color1.x;
                        double cy = color0.y * (1 - alpha) + alpha * color1.y;
                        double cz = color0.z * (1 - alpha) + alpha * color1.z;

                        if (x > 0 && y > 0 && cam.sizeX > x && cam.sizeY > y){
                                image[x][y].r = (int)cx;
                                image[x][y].g = (int)cy;
                                image[x][y].b = (int)cz;
                        }

                        if (d < 0){
                                y++;
                                d += 2*(y0 - y1 + x1 - x0);
                        }
                        else{
                                d += 2*(y0 - y1);
                        }
                }
        }
        else if (slope >= -1){
                int y = y0;
                double d = 2*(y0 - y1) + x1 - x0;
                for (int x = x0; x <= x1; x++){
                        alpha = (x - x0) / (x1 - x0);

                        double cx = color0.x * (1 - alpha) + alpha * color1.x;
                        double cy = color0.y * (1 - alpha) + alpha * color1.y;
                        double cz = color0.z * (1 - alpha) + alpha * color1.z;

                        if (x > 0 && y > 0 && cam.sizeX > x && cam.sizeY > y){
                                image[x][y].r = (int)cx;
                                image[x][y].g = (int)cy;
                                image[x][y].b = (int)cz;
                        }

                        if (d < 0){
                                y--;
                                d += 2*(y1 - y0 + x1 - x0);
                        }
                        else{
                                d += 2*(y1 - y0);
                        }
                }
        }
        else {
                int x = x0;
                double d = 2*(x0 - x1) + y1 - y0;
                for (int y = y0; y >= y1; y--){
                        alpha = (x - x0) / (x1 - x0);

                        double cx = color0.x * (1 - alpha) + alpha * color1.x;
                        double cy = color0.y * (1 - alpha) + alpha * color1.y;
                        double cz = color0.z * (1 - alpha) + alpha * color1.z;

                        if (x > 0 && y > 0 && cam.sizeX > x && cam.sizeY > y){
                                image[x][y].r = (int)cx;
                                image[x][y].g = (int)cy;
                                image[x][y].b = (int)cz;
                        }

                        if (d < 0){
                                x++;
                                d += 2*(x0 - x1 + y0 - y1);
                        }
                        else{
                                d += 2*(x0 - x1);
                        }
                }
        }
}