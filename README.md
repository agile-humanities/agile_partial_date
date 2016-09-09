# Partial Date - Feeds Compatible

This version of Partial Date allows you to use the Feeds module to import components of a partial date field.

## Installation
To install, either use this module in place of partial_date, or use the included patch
to patch your partial date module. Install and enable Feeds.

When configuring a Feeds importer for an entity that contains a partial date, the Mappings section will contain Partial Date components that you can select as targets. These can include the following:

* my partial date field: Approximate (bool)
* my partial date field: Long text description
* my partial date field: Short text description
* my partial date field: from: year
* my partial date field: from: year
* my partial date field: from: year
* my partial date field: from: year - estimate
* my partial date field: from: month
* my partial date field: from: month - estimate
* my partial date field: from: day
* my partial date field: from: day - estimate
* my partial date field: from: hour
* my partial date field: from: hour - estimate
* my partial date field: from: minute
* my partial date field: from: minute - estimate
* my partial date field: from: second
* my partial date field: from: second - estimate
* my partial date field: from: timezone
* my partial date field: to: year
* my partial date field: to: year - estimate
* my partial date field: to: month
* my partial date field: to: month - estimate
* my partial date field: to: day
* my partial date field: to: day - estimate
* my partial date field: to: hour
* my partial date field: to: hour - estimate
* my partial date field: to: minute
* my partial date field: to: minute - estimate
* my partial date field: to: second
* my partial date field: to: second - estimate
* my partial date field: to: timezone

Not all of the above components will be available in the list.  "To" components only exist if this field is of type Partial Date Range. Also, only the elements that are enabled for this field instance will be accessible. Configure this at Admin > Structure > Content types > [my content type].

A Partial date field can be set up with customized labels for range estimates. For example, the years 1500 to 1599 may be called "16th century". The feeds importer checks for labels, so values that can be imported (e.g. the column in your CSV) may be "1500|1599" or "16th century" to the same effect. Please note that they are case sensitive. If the label is not recognized the value will not be imported.

To import months, please use the numeric value, i.e. either "02" or "2" for February.

# Partial Date - Contains filter

The Partial Date Contains filter is designed to be a views exposed filter
that allows a user to specify a date (year, year-month, or year-month-day)
and will match against partial date or partial date range values that
have some overlap with the specified (vague) date.

e.g.
User enters '2014'. This matches with the partial date range '2014-Aug to 2015-Jan',
the partial date 2014-Jan-02, and the partial date estimate 2010|2019.

User enters '2014-Jan'. This matches with the partial date 2014-Jan-02,
the partial date estimate 2010|2019, but not with the partial date range
 '2014-Aug to 2015-Jan'.

To enable the Partial Date Contains Filter:
* Create a view that contains objects with partial date (or partial date range) fields.
* Add a filter criteria, and select the name of the field. There will be over 10
_sub-fields_ appearing as options ("Content: myfield (myfield:data)",
"Content: myfield (myfield:timestamp)", ...) but ignore these. Select the
one that is purely the name of the field (with no parentheses after it)
* For the Date Selection Form Element, choose "Partial Select". 
* Change the operator to "Contains".
* Expose this filter if desired.

