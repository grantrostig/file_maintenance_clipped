#include <arpa/inet.h>
#include <cassert>
#include <fstream>
#include <iostream>

#include "global_entities.h"
#include "actions.h"
#include "action_dialog.h"
#include "window_panel.h"
#include "interaction_result.h"
// BEGIN OF SNIP todo
// END OF SNIP
using std::cin, std::cout, std::endl, std::cerr, std::clog;

using namespace std::string_literals;

/*InteractionResult action_print_categories( State_menu &) {
//    cerr << "int action_print_categories( State &) {" << endl;
//    return InteractionResult { {}, {}, {}, {}, InteractionResultNav::retain_menu };
//}

//InteractionResult action_print_search_entries( State_menu &) {
//    cerr << "int action_print_search_entries( State &) {" << endl;
//    return InteractionResult { {}, {}, {}, {}, InteractionResultNav::retain_menu };
//}

//InteractionResult action_entry_viewing( State_menu &) {
//    cerr << "int action_entry_viewing( State &) {" << endl;
//    return InteractionResult { {}, {}, {}, {}, InteractionResultNav::retain_menu };
//}*/

InteractionResult action_delete_all( State_menu & state ) {
    cerr << "int action_delete_all( State &) {" << endl;
    // todo: delete all
    state.getApplication_data_sp()->setIs_data_unsaved(true);
    InteractionResult ir = action_dialog_modal_notify( state, "All user data have been removed from the memory of the application.  If you save now, the saved file will be empty.");
    return ir;
}

InteractionResult action_save_as_changes_to_disk( State_menu & state ) {
    cerr << "int action_save_changes_to_disk( State &) " << endl;
    //cerr << "saving application data: "<<state.getApplication_data()->getInt_data()<<endl;
    // todo: get file name
    InteractionResult ir = action_save_changes_to_disk( state );
    return ir;
}

std::streamoff size_of_data( std::iostream & stream ) {
    auto old_exceptions { stream.exceptions() };
    stream.exceptions(stream.exceptions()|(std::ios_base::failbit & std::ios_base::badbit));
    stream.seekg( 0, std::ios_base::end );  // https://stackoverflow.com/questions/4432793/size-of-stringstream/4432843#4432843
    std::streamoff size { stream.tellg() };
    stream.seekg( 0, std::ios_base::beg );
    stream.exceptions(old_exceptions);
    return size;
}

InteractionResult action_save_changes_to_disk( State_menu & state ) {
    // disk file layout:  	version_size char, version char*,
    //					  	adata_size uint16, adata_serialized char*,
    //						pdata_size uint32, pdata_serialized_char*,
    InteractionResult 		ir  	{};  // to be returned
    InteractionResult 		ir_temp {};  // temporary for handling intermediate values.
    InteractionResultNav 	nav  	{};
                                    cerr << "int action_save_changes_to_disk( State &) " << endl;
    // if ( io_table_persons.rows.size() == 0 ) ir = action_dialog_modal_deny( state, "Warning: there are no data records to save, do you wish to proceed?: ");
    // if ( ir.hot_key != proceed ) {  todo: //ir = ?; //return ir; //}

    // BEGIN OF SNIP todo
    // END OF SNIP
    state.getApplication_data_sp()->setIs_data_unsaved( false );

    state.action_push( InteractionCategory::dialogn );  // Next 3 lines are one unit.
    ir_temp 		= action_dialog_modal_notify( state, "All user and relevant program data have been saved to disk." );
    nav 		= find_interaction_result_nav( ir_temp.hot_key, state.action_top() );
    ir.navigation 	= nav;
    return ir;
}

InteractionResult action_load_data_from_disk( State_menu & state) {
    InteractionResult ir {};

    if ( not state.getApplication_data_sp()->getIs_data_unsaved() ) {
        // todo:  verify with user if unsaved data existing.
    }

    // try {  // to catch IO bad() errors.
                                    cerr << "int action_load_data_from_disk( State &) " << endl;
    std::ifstream ifstream_adata_pdata { DEFAULT_FILE_NAME, std::ios_base::binary | std::ios_base::in };
    if ( ifstream_adata_pdata.fail() || ifstream_adata_pdata.bad() ) {
        ir = action_dialog_modal_notify( state, "Error: cannot open file, no data such file exists, or you don't have permission to read it."); // todo: I just return after failure? Is there a subtle issue with any returned hot key?  Should it be cleared?
        return ir;
    }
    // BEGIN OF SNIP todo
    // END OF SNIP
    state.getApplication_data_sp()->setIs_data_unsaved(false);
    ir = action_dialog_modal_notify( state, "All user data have been loaded from disk, replacing any prior data.");
    InteractionResultNav nav = find_interaction_result_nav( ir.hot_key, InteractionCategory::menu );
    ir.navigation 			 = nav;
    return ir;
}

//also need: InteractionResult action_save_as_data_from_disk( State_menu & state) {  // save to a new or existing file, which is not from the current name.
InteractionResult action_load_as_data_from_disk( State_menu & state) {  // load from an existing file, which is not from the current name.
    cerr << "int action_load_as_data_from_disk( State &) " << endl;
    //todo: get file name, also decide if new name and location is new default?
    InteractionResult ir = action_load_data_from_disk( state );
    ir = action_dialog_modal_notify( state, "All user data have been loaded from disk. Note: Please take care where you will save the data.  TODO TODO!!!! !");
    InteractionResultNav nav = find_interaction_result_nav( ir.hot_key, InteractionCategory::menu );
    ir.navigation 			 = nav;
    return ir;
}

InteractionResult action_backup_data( State_menu & state ) {
    cerr << "int action_backup_data( State &) " << endl;
    // todo: do something.
    InteractionResult 	 ir  = action_dialog_modal_notify( state, "All user data have been backed up to disk in a backup format. Note: data have not been saved in the normal format in the normal location.  Please also normally save any data you wish to save for normal use of the application!");
    InteractionResultNav nav = find_interaction_result_nav( ir.hot_key, InteractionCategory::menu );
    ir.navigation 			 = nav;
    return ir;
}

InteractionResult action_screen_size( State_menu &) {
    cerr << "int action_screen_size( State &) " << endl;
    // todo: do something
    return InteractionResult { {}, {}, {}, {}, InteractionResultNav::retain_menu };
}

InteractionResult action_advanced_settings_selection( State_menu &) {
    cerr << "int action_advanced_settings_selection:" << endl;
    // todo: do something
    return InteractionResult { {}, {}, {}, {}, InteractionResultNav::retain_menu };
}
