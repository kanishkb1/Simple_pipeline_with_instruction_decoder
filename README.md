# Simple_pipeline_with_instruction_decoder
The main aim of the project is to develop the simulated pipeline with an instruction decoder.

**Pipeline follow three stages are as follows-**
<ol>
  <li> 1 stage for fetch (IF) </li>
  <li> 1 stage for decode (ID) </li>
  <li> 1 stage for execution (EX) </li>
</ol>

Additionally, the pipeline supports 4B fixed-length instructions, which stands 1B for opcode, 1B for destination and 2B for two operands. The destination and left operands are  always registers. The right operand can be either register or an immediate value.

![The San Juan Mountains are beautiful!](https://github.com/kanishkb1/Simple_pipeline_with_instruction_decoder/blob/main/traces/pipeline.png "Pipeline Flow-diagram")


**Output for the pipeline which updates the register values (Number of registers=16), total execution cycles and IPC.

Registers: 
----------------------------------------
  R0:  8          |   R1:  808       
----------------------------------------
  R2:  161        |   R3:  696       
----------------------------------------
  R4:  404        |   R5:  707       
----------------------------------------
  R6:  957        |   R7:  2443      
----------------------------------------
  R8:  772        |   R9:  1468      
----------------------------------------
  R10: 104        |   R11: 2241      
----------------------------------------
  R12: 1534       |   R13: 315       
----------------------------------------
  R14: 89         |   R15: 425       
----------------------------------------

Total execution cycles: 152

IPC: 0.986842
