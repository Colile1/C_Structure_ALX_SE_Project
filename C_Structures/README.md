## Build Instructions

### Linux/WSL
```bash
sudo apt-get install libsdl2-dev libeigen3-dev libglm-dev libglew-dev
mkdir build && cd build
cmake ..
make -j4
./C_Structures
```

## CSV Format  
- Nodes: `NODE x y z fixed`  
- Beams: `BEAM start_index end_index youngs_modulus cross_section`  
Example:  
```
NODE 0 0 0 1
BEAM 0 1 2e11 0.01
