import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/usuario/Documentos/GitHub/IR2134/TASK3y4_NAT/src/install/rmf_demos_fleet_adapter'
