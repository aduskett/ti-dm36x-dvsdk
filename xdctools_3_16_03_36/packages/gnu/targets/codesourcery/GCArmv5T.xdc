/* 
 *  Copyright (c) 2008 Texas Instruments and others.
 *  All rights reserved. This program and the accompanying materials
 *  are made available under the terms of the Eclipse Public License v1.0
 *  which accompanies this distribution, and is available at
 *  http://www.eclipse.org/legal/epl-v10.html
 * 
 *  Contributors:
 *      Texas Instruments - initial implementation
 * 
 * */
import gnu.targets.ITarget;

/*!
 *  ======== GCArmv5T.xdc ========
 *  This module defines an embedded target for Linux on Arm. The target
 *  generates code compatible with the "v5TE" architecture.
 *
 */
metaonly module GCArmv5T inherits gnu.targets.ITarget {
    override readonly config string name                = "GCArmv5T";   
    override readonly config string os                  = "Linux";      
    override readonly config string suffix              = "470MV";
    override readonly config string isa                 = "v5T";
    override readonly config xdc.bld.ITarget.Model model= {
        endian: "little"
    };

    override readonly config string rts = "gnu.targets.codesourcery.rtsv5T";
    override config string platform     = "ti.platforms.evm2530";
    
    override config string LONGNAME = "/bin/arm-none-linux-gnueabi-gcc";

    override readonly config Bool CYGWIN     = true;

    override readonly config String stdInclude = "gnu/targets/codesourcery/std.h";

    override config ITarget.Options ccOpts = {
        prefix: "-fPIC -Wunused",
        suffix: "-Dfar= "
    };

    override config ITarget.Options lnkOpts = {
        prefix: "",
        suffix: "-lstdc++ -L$(rootDir)/$(GCCTARG)/lib"
    };
        
        
    /*
     *  ======== compatibleSuffixes ========
     */
    override config String compatibleSuffixes[] = ["v5T", "v5t"];

    override readonly config xdc.bld.ITarget.StdTypes stdTypes = {
        t_IArg          : { size: 4, align: 4 },
        t_Char          : { size: 1, align: 1 },
        t_Double        : { size: 8, align: 4 },
        t_Float         : { size: 4, align: 4 },
        t_Fxn           : { size: 4, align: 4 },
        t_Int           : { size: 4, align: 4 },
        t_Int8          : { size: 1, align: 1 },
        t_Int16         : { size: 2, align: 2 },
        t_Int32         : { size: 4, align: 4 },
        t_Int64         : { size: 8, align: 4 },
        t_Long          : { size: 4, align: 4 },
        t_LDouble       : { size: 8, align: 4 },
        t_LLong         : { size: 8, align: 4 },
        t_Ptr           : { size: 4, align: 4 },
        t_Short         : { size: 2, align: 2 },
    };
}
/*
 *  @(#) gnu.targets.codesourcery; 1, 0, 0, 0,241; 2-24-2010 16:24:01; /db/ztree/library/trees/xdctargets/xdctargets-b36x/src/
 */

