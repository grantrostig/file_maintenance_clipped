#ifndef FIELD_NAVIGATION_INTERACTION_MAP_H
#define FIELD_NAVIGATION_INTERACTION_MAP_H
#include <vector>
#include "interaction_result.h"

struct FieldNavInteractionRelation {
    InteractionCategory	                 category 			{InteractionCategory::na};  // Type of interaction (action_) we are prior to completing and returning from.
    Lib_tty::FieldCompletionNav 	 field_nav 			{Lib_tty::FieldCompletionNav::na};  	// Result of last (user?) interaction, which will determine which InteractionResultNav that will be returned.
    InteractionResultNav interaction_nav 	{InteractionResultNav::na};	// Return value to be returned by the interaction that has just been executed. This began as what the menu system sees, but was extended to include moving between fields during data entry on a row, and then further.
};

class FieldNavigationInteractionMap {
public:
    std::vector<FieldNavInteractionRelation> mappings;
    bool verify() const;
};

/* This vector<> mapping defines what actions (InteractionResultNav) are taken on receipt of a
 * hot_key.Lib_tty::FieldCompletionNav.  Different situations are differentiated by InteractionCategory.
 */
static const FieldNavigationInteractionMap fieldNavigationInteractionMap
{  // todo: get rid of global if possible, perhaps adding to the "statu" data structure.  ALSO: figure out if this level of detail, or any of this is necessary.  Seemed like a good idea at the time. LOL
std::vector<FieldNavInteractionRelation>
{
        /*	Type of interaction (action_) we are prior to completing and returning from.
                                        Result of last (user?) interaction, which will determine which InteractionResultNav that will be returned.
                                                                                Return value to be returned by the interaction that has just been executed. This began as what the menu system sees, but was extended to include moving between fields during data entry on a row, and then further.
*/
         { InteractionCategory::menu, 	    Lib_tty::FieldCompletionNav::esc, 				InteractionResultNav::prior_menu_discard_value }, // for example, esc on menu, should take you back one.
         { InteractionCategory::menu, 	    Lib_tty::FieldCompletionNav::exit_immediately, 	InteractionResultNav::exit_pgm_immediately },
         { InteractionCategory::menu, 	    Lib_tty::FieldCompletionNav::interrupt_signal, 	InteractionResultNav::exit_pgm_immediately },
    { InteractionCategory::menu, 	    Lib_tty::FieldCompletionNav::quit_signal,		InteractionResultNav::exit_pgm_immediately },
    { InteractionCategory::menu, 	    Lib_tty::FieldCompletionNav::kill_signal,		InteractionResultNav::exit_pgm_immediately },
    { InteractionCategory::menu, 	    Lib_tty::FieldCompletionNav::exit_with_prompts, 	InteractionResultNav::exit_pgm_with_prompts },
    { InteractionCategory::menu, 	    Lib_tty::FieldCompletionNav::eof, 				InteractionResultNav::exit_pgm_immediately },
    //{ InteractionCategory::menu, 	    Lib_tty::FieldCompletionNav::help, 				InteractionResultNav::retain_menu },

         { InteractionCategory::menu, 		Lib_tty::FieldCompletionNav::browse_up, 			InteractionResultNav::na },

         { InteractionCategory::menu, 	    Lib_tty::FieldCompletionNav::browse_down, 		InteractionResultNav::retain_menu },  // normal response to menu selection prompt.
         { InteractionCategory::menu, 		Lib_tty::FieldCompletionNav::up_one_field, 		InteractionResultNav::na },
    { InteractionCategory::menu, 	    Lib_tty::FieldCompletionNav::down_one_field, 	InteractionResultNav::retain_menu },  // normal response to menu selection prompt.
    { InteractionCategory::menu, 	    Lib_tty::FieldCompletionNav::page_up, 			InteractionResultNav::na },
    { InteractionCategory::menu, 	    Lib_tty::FieldCompletionNav::page_down,		 	InteractionResultNav::na },
    { InteractionCategory::menu, 	    Lib_tty::FieldCompletionNav::save_form_as_is,	InteractionResultNav::na },
    { InteractionCategory::menu, 	    Lib_tty::FieldCompletionNav::skip_to_end_of_fields, InteractionResultNav::na },
    { InteractionCategory::menu, 	    Lib_tty::FieldCompletionNav::skip_one_field, 	InteractionResultNav::na },
    { InteractionCategory::menu, 	    Lib_tty::FieldCompletionNav::no_result, 			InteractionResultNav::no_result },
    { InteractionCategory::menu, 	    Lib_tty::FieldCompletionNav::na, 				InteractionResultNav::na },

    { InteractionCategory::dialog, 	    Lib_tty::FieldCompletionNav::esc, 				InteractionResultNav::prior_menu },  // for example, if when <Return> to continue, then stop listing the items.
    { InteractionCategory::dialog, 	    Lib_tty::FieldCompletionNav::exit_immediately, 	InteractionResultNav::exit_pgm_immediately },
    { InteractionCategory::dialog, 	    Lib_tty::FieldCompletionNav::interrupt_signal, 	InteractionResultNav::exit_pgm_immediately },
    { InteractionCategory::dialog, 	    Lib_tty::FieldCompletionNav::quit_signal,		InteractionResultNav::exit_pgm_immediately },
    { InteractionCategory::dialog, 	    Lib_tty::FieldCompletionNav::kill_signal,		InteractionResultNav::exit_pgm_immediately },
    { InteractionCategory::dialog, 	    Lib_tty::FieldCompletionNav::exit_with_prompts, 	InteractionResultNav::exit_pgm_with_prompts },
    { InteractionCategory::dialog, 	    Lib_tty::FieldCompletionNav::eof, 				InteractionResultNav::exit_pgm_immediately },
    //{ InteractionCategory::dialog, 	    Lib_tty::FieldCompletionNav::help, 				InteractionResultNav::na },
    { InteractionCategory::dialog, 		Lib_tty::FieldCompletionNav::browse_up, 			InteractionResultNav::na },
    { InteractionCategory::dialog, 	    Lib_tty::FieldCompletionNav::browse_down, 		InteractionResultNav::na },
    { InteractionCategory::dialog, 		Lib_tty::FieldCompletionNav::up_one_field, 		InteractionResultNav::retain_menu },
    { InteractionCategory::dialog, 	    Lib_tty::FieldCompletionNav::down_one_field, 	InteractionResultNav::retain_menu },
    { InteractionCategory::dialog, 	    Lib_tty::FieldCompletionNav::page_up, 			InteractionResultNav::retain_menu },
    { InteractionCategory::dialog, 	    Lib_tty::FieldCompletionNav::page_down,		 	InteractionResultNav::retain_menu },
    { InteractionCategory::dialog, 	    Lib_tty::FieldCompletionNav::save_form_as_is,	InteractionResultNav::retain_menu },
    { InteractionCategory::dialog, 	    Lib_tty::FieldCompletionNav::skip_to_end_of_fields, InteractionResultNav::retain_menu },
    { InteractionCategory::dialog, 	    Lib_tty::FieldCompletionNav::skip_one_field, 	InteractionResultNav::na },
    { InteractionCategory::dialog, 	    Lib_tty::FieldCompletionNav::no_result, 			InteractionResultNav::no_result },
    { InteractionCategory::dialog, 	    Lib_tty::FieldCompletionNav::na, 				InteractionResultNav::na },

    { InteractionCategory::dialogn, 	    Lib_tty::FieldCompletionNav::esc, 				InteractionResultNav::prior_menu },  // for example, if when <Return> to continue, then stop listing the items.
    { InteractionCategory::dialogn, 	    Lib_tty::FieldCompletionNav::exit_immediately, 	InteractionResultNav::exit_pgm_immediately },
    { InteractionCategory::dialogn, 	    Lib_tty::FieldCompletionNav::interrupt_signal, 	InteractionResultNav::exit_pgm_immediately },
    { InteractionCategory::dialogn, 	    Lib_tty::FieldCompletionNav::quit_signal,		InteractionResultNav::exit_pgm_immediately },
    { InteractionCategory::dialogn, 	    Lib_tty::FieldCompletionNav::kill_signal,		InteractionResultNav::exit_pgm_immediately },
    { InteractionCategory::dialogn, 	    Lib_tty::FieldCompletionNav::exit_with_prompts, 	InteractionResultNav::exit_pgm_with_prompts },
    { InteractionCategory::dialogn, 	    Lib_tty::FieldCompletionNav::eof, 				InteractionResultNav::exit_pgm_immediately },
    //{ InteractionCategory::dialog, 	    Lib_tty::FieldCompletionNav::help, 				InteractionResultNav::na },
    { InteractionCategory::dialogn, 		Lib_tty::FieldCompletionNav::browse_up, 			InteractionResultNav::na },
    { InteractionCategory::dialogn, 	    Lib_tty::FieldCompletionNav::browse_down, 		InteractionResultNav::na },
    { InteractionCategory::dialogn, 		Lib_tty::FieldCompletionNav::up_one_field, 		InteractionResultNav::retain_menu },
    { InteractionCategory::dialogn, 	    Lib_tty::FieldCompletionNav::down_one_field, 	InteractionResultNav::retain_menu },
    { InteractionCategory::dialogn, 	    Lib_tty::FieldCompletionNav::page_up, 			InteractionResultNav::retain_menu },
    { InteractionCategory::dialogn, 	    Lib_tty::FieldCompletionNav::page_down,		 	InteractionResultNav::retain_menu },
    { InteractionCategory::dialogn, 	    Lib_tty::FieldCompletionNav::save_form_as_is,	InteractionResultNav::retain_menu },
    { InteractionCategory::dialogn, 	    Lib_tty::FieldCompletionNav::skip_to_end_of_fields, InteractionResultNav::retain_menu },
    { InteractionCategory::dialogn, 	    Lib_tty::FieldCompletionNav::skip_one_field, 	InteractionResultNav::na },
    { InteractionCategory::dialogn, 	    Lib_tty::FieldCompletionNav::no_result, 			InteractionResultNav::no_result },
    { InteractionCategory::dialogn, 	    Lib_tty::FieldCompletionNav::na, 				InteractionResultNav::na },

    { InteractionCategory::field, 	    Lib_tty::FieldCompletionNav::esc, 				InteractionResultNav::prior_menu },  // for example, if when <Return> to continue, then stop listing the items.
    { InteractionCategory::field, 	    Lib_tty::FieldCompletionNav::exit_immediately, 	InteractionResultNav::exit_pgm_immediately },
    { InteractionCategory::field, 	    Lib_tty::FieldCompletionNav::interrupt_signal, 	InteractionResultNav::exit_pgm_immediately },
    { InteractionCategory::field, 	    Lib_tty::FieldCompletionNav::quit_signal,		InteractionResultNav::exit_pgm_immediately },
    { InteractionCategory::field, 	    Lib_tty::FieldCompletionNav::kill_signal,		InteractionResultNav::exit_pgm_immediately },
    { InteractionCategory::field, 	    Lib_tty::FieldCompletionNav::exit_with_prompts, 	InteractionResultNav::exit_pgm_with_prompts },
    { InteractionCategory::field, 	    Lib_tty::FieldCompletionNav::eof, 				InteractionResultNav::exit_pgm_immediately },
    //{ InteractionCategory::field, 	    Lib_tty::FieldCompletionNav::help, 				InteractionResultNav::na },						// help is handled prior to this decision point.
    { InteractionCategory::field, 		Lib_tty::FieldCompletionNav::browse_up, 			InteractionResultNav::up_one_field },  // NOTE: browse_up is also used to navigate between valid_values.
    { InteractionCategory::field, 	    Lib_tty::FieldCompletionNav::browse_down, 		InteractionResultNav::down_one_field },  // NOTE: browse_down is also used to navigate between valid_values.
    { InteractionCategory::field, 		Lib_tty::FieldCompletionNav::up_one_field, 		InteractionResultNav::up_one_field },
    { InteractionCategory::field, 	    Lib_tty::FieldCompletionNav::down_one_field, 	InteractionResultNav::down_one_field },
    { InteractionCategory::field, 	    Lib_tty::FieldCompletionNav::page_up, 			InteractionResultNav::up_one_block },
    { InteractionCategory::field, 	    Lib_tty::FieldCompletionNav::page_down,		 	InteractionResultNav::down_one_block },
    { InteractionCategory::field, 	    Lib_tty::FieldCompletionNav::save_form_as_is,	InteractionResultNav::save_form_as_is },
    { InteractionCategory::field, 	    Lib_tty::FieldCompletionNav::skip_to_end_of_fields, InteractionResultNav::skip_to_end_of_fields },
    { InteractionCategory::field, 	    Lib_tty::FieldCompletionNav::skip_one_field, 	InteractionResultNav::skip_one_field },
    { InteractionCategory::field, 	    Lib_tty::FieldCompletionNav::no_result, 			InteractionResultNav::no_result },
    { InteractionCategory::field, 	    Lib_tty::FieldCompletionNav::na, 				InteractionResultNav::na },

    { InteractionCategory::detail_row, 	Lib_tty::FieldCompletionNav::esc, 				InteractionResultNav::prior_menu },  // for example, if when <Return> to continue, then stop listing the items.
    { InteractionCategory::detail_row, 	Lib_tty::FieldCompletionNav::exit_immediately, 	InteractionResultNav::exit_pgm_immediately },
    { InteractionCategory::detail_row, 	Lib_tty::FieldCompletionNav::interrupt_signal, 	InteractionResultNav::exit_pgm_immediately },
    { InteractionCategory::detail_row, 	Lib_tty::FieldCompletionNav::quit_signal,		InteractionResultNav::exit_pgm_immediately },
    { InteractionCategory::detail_row, 	Lib_tty::FieldCompletionNav::kill_signal,		InteractionResultNav::exit_pgm_immediately },
    { InteractionCategory::detail_row, 	Lib_tty::FieldCompletionNav::exit_with_prompts, 	InteractionResultNav::exit_pgm_with_prompts },
    { InteractionCategory::detail_row, 	Lib_tty::FieldCompletionNav::eof, 				InteractionResultNav::exit_pgm_immediately },
    //{ InteractionCategory::detail_row, 	Lib_tty::FieldCompletionNav::help, 				InteractionResultNav::na },
    { InteractionCategory::detail_row, 	Lib_tty::FieldCompletionNav::browse_up, 			InteractionResultNav::prior_row },
    { InteractionCategory::detail_row, 	Lib_tty::FieldCompletionNav::browse_down, 		InteractionResultNav::next_row },
    { InteractionCategory::detail_row, 	Lib_tty::FieldCompletionNav::up_one_field, 		InteractionResultNav::prior_row },
    { InteractionCategory::detail_row, 	Lib_tty::FieldCompletionNav::down_one_field, 	InteractionResultNav::next_row },
    { InteractionCategory::detail_row, 	Lib_tty::FieldCompletionNav::page_up, 			InteractionResultNav::up_one_block },
    { InteractionCategory::detail_row, 	Lib_tty::FieldCompletionNav::page_down,		 	InteractionResultNav::down_one_block },
    { InteractionCategory::detail_row, 	Lib_tty::FieldCompletionNav::save_form_as_is,	InteractionResultNav::prior_menu },
    { InteractionCategory::detail_row, 	Lib_tty::FieldCompletionNav::skip_to_end_of_fields, InteractionResultNav::last_row },
    { InteractionCategory::detail_row, 	Lib_tty::FieldCompletionNav::skip_one_field, 	InteractionResultNav::next_row },
    { InteractionCategory::detail_row, 	Lib_tty::FieldCompletionNav::no_result, 			InteractionResultNav::no_result },
    { InteractionCategory::detail_row, 	Lib_tty::FieldCompletionNav::na, 				InteractionResultNav::na }

    //  ::help - is similar to field, because it it probably called during field entry, so we just use ::field  // todo: complete this: OK so what if help is called from a menu or wizard?  Well then we can do ::field_help, ::menu_help ...
    // { InteractionCategory::master_row, 	Lib_tty::FieldCompletionNav::na, 				InteractionResultNav::na }
}
};

#endif // FIELD_NAVIGATION_INTERACTION_MAP_H
