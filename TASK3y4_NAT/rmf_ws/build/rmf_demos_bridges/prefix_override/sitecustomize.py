import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/usuario/Documentos/GitHub/IR2134/TASK3y4_NAT/rmf_ws/install/rmf_demos_bridges'
