
typedef unsigned char uint8_t;
typedef unsigned int uint32_t;

uint8_t WQRHash(uint32_t str){
       
    uint8_t bit0_31[4];
    
    for(int i=3;i>=0;i--)
    	bit0_31[i] = str>>(8*i);


    uint8_t hash = 5381;  //Daniel J.Bernstein's hash function
      for(int i = 0; i < 4; i++)  
      {  
         hash = ((hash << 3) + hash) + bit0_31[i];  //we change the argument 5 to 3
      }  
    
    return hash;  
}  

struct CFG_entry{
	uint8_t current_pc;
	uint8_t branch_pc;
	uint8_t current_pc_hash;
	uint8_t branch_pc_hash;
};

int main(){
	CFG_entry first_entry;
	
	uint32_t true_current_pc = 0x8120;
	uint32_t true_branch_pc = 0x8133;
	
	first_entry.branch_pc = 0x33;
	first_entry.current_pc = 0x20;
	first_entry.current_pc_hash = WQRHash(true_current_pc);
	first_entry.branch_pc_hash = WQRHash(true_branch_pc);
	
	return 0;

} 
